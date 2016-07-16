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
    max_gross_weight
    empty_weight
    reference_datum_position
    empty_weight_CG_position
    station_load.
    empty_weight_pitch_MOI
    empty_weight_roll_MOI
    empty_weight_yaw_MOI
    empty_weight_coupled_MOI
    cruise_lift_scalar
    parasite_drag_scalar
    induced_drag_scalar
    elevator_effectiveness
    rudder_effectiveness
    pitch_stability
    yaw_stability
    elevator_trim_effectiveness
    engine_type
    Engine.
    fuel_flow_scalar

    // by default this vector is false. Every time a key,value pair is found, the value is changed to true
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
            for (size_t n=0; n<name.size() && !name_done[n]; n++)
            {
                double val = 0.;
                if ( foundKeyValue(line, name[n], val) ) acft.insertKeyValue(name[n],val);
            }
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
