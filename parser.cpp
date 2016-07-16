#include "parser.h"

Aircraft parseCfgFile(ifstream &ac_file)
{
    Aircraft acft;

    // Listing all key-value sets required
    vector<string> name;
    name.push_back("wing_area");
    name.push_back("wing_span");
    name.push_back("wing_root_chord");
    name.push_back("wing_sweep");
    name.push_back("oswald_efficiency_factor");
    name.push_back("wing_pos_apex_lon");
    name.push_back("wing_pos_apex_vert");
    name.push_back("htail_area");
    name.push_back("htail_span");
    name.push_back("htail_pos_lon");
    name.push_back("htail_pos_vert");
    name.push_back("htail_incidence");
    name.push_back("htail_sweep");
    name.push_back("vtail_area");
    name.push_back("vtail_span");
    name.push_back("vtail_pos_lon");
    name.push_back("vtail_pos_vert");
    name.push_back("vtail_sweep");
    name.push_back("max_gross_weight");
    name.push_back("empty_weight");
    name.push_back("reference_datum_position");
    name.push_back("empty_weight_cg_position");
    //station_load.
    name.push_back("cruise_lift_scalar");
    name.push_back("parasite_drag_scalar");
    name.push_back("induced_drag_scalar");
    name.push_back("elevator_effectiveness");
    name.push_back("rudder_effectiveness");
    name.push_back("pitch_stability");
    name.push_back("yaw_stability");
    name.push_back("elevator_trim_effectiveness");
    //[GeneralEngineData]
    name.push_back("engine_type"); //0=Piston, 1=Jet, 2=None, 3=Helo-Turbine, 4=Rocket, 5=Turboprop
    //Engine.
    name.push_back("fuel_flow_scalar");
    //[propeller]
    name.push_back("static_thrust");
    //[TurbineEngineData]
    name.push_back("powerspecificfuelconsumption");
    //name.push_back("PowerSpecificFuelConsumption");
    //[contact_points]
    //point.
    //flaps.
    //flaps-position.
    //[fuel]
    //LeftMain

    // By default this vector is false. Every time a key,value pair is found, the value is changed to true
    vector<bool> name_done;
    for (unsigned i=0; i<name.size(); i++)
        name_done.push_back(false);

    // Starting parser:
    cout<<"PARSING AICRAFT.CFG"<<endl;
    map<string, double> data;

    // Parsing aircraft.cfg
    string line;
    while ( !ac_file.eof() )
    {
        // reading line
        getline(ac_file,line);
        // Cleaning the line (lowering, removing trailing comments and eliminating white spaces):
        cleanLine(line);
        //cout<<"c.. "<<line<<endl; // uncomment for debugging

        // Checking if the line is a comment. If it is, ignore it and continue
        if ( !isCommentLine(line) )
        {
            // Looping trough all the key,value pairs required, if not already inserted
            for (size_t n=0; n<name.size(); n++)
            {
                if (name_done[n]) continue;
                double val = 0.;
                if ( foundKeyValue(line, name[n], val) )
                {
                    acft.insertKeyValue(name[n],val);
                    name_done[n] = true;
                }
            }
        }
    }
    // Check everything is loaded correctly:
    for (unsigned n = 0; n<name_done.size(); n++)
    {
        if (!name_done[n])
        {
            cerr<<"WARNING: "<<name[n]<<" NOT LOADED "<<endl;
            assert(name_done[n] == true);
        }
    }

    return acft;
}


bool isCommentLine(string &line)
{
    size_t found_c;
    size_t found = string::npos;
    for (size_t i=0; i<c_type.size(); i++ )
    {
        found_c = line.find(c_type[i]);
        found = min(found, found_c);
    }

    if ( found!=string::npos )
    {
        // If on position 0 the complete line is a comment
        if ( found == 0 ) return true;
    }

    return false;
}


void cleanLine(string &line)
{
    // Lowering all characters:
    transform(line.begin(), line.end(), line.begin(), ::tolower);

    // Remove trailing comments
    size_t found_c;
    size_t found = string::npos;
    for (size_t i=0; i<c_type.size(); i++ )
    {
        found_c = line.find(c_type[i]);
        found = min(found, found_c);
    }

    if ( found!=string::npos )
    {
        // If on position greater than 0, the last part of the line is dropped
        if ( found > 0 )    line = line.substr(0,found-1);
    }

    // kill any white space present
    string::iterator end_pos = remove(line.begin(), line.end(), ' ');
    line.erase(end_pos, line.end());
    // Now line is a string without spaces that can be broken at the symbol '='
}


bool foundKeyValue(string &line, string &name, double &val)
{
    string new_name = name + "="; // new_name stores "name="
    size_t found_ew = line.find(new_name);
    if (found_ew==string::npos) return false;

    size_t found_s = line.find("="); // all lines are "name=value"
    string line_tmp = line.substr(found_s+1,line.size()); // Isolating value after "="

    stringstream line_val;
    line_val<<line_tmp;
    line_val>>val;
    return true;
}
