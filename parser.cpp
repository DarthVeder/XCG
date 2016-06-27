#include "parser.h"

enum t_wing
{
    main_wing=0,
    tail=1,
    rudder=2
};

Aircraft parseCfgFile(ifstream &ac_file)
{
    Aircraft acft;
    acft.wing.resize(3);
    acft.wing[main_wing].setName("main wing");
    acft.wing[tail].setName("tail");
    acft.wing[rudder].setName("rudder");

    // Parsing aircraft.cfg
    string line;

    while ( !ac_file.eof() )
    {
        // reading line
        getline(ac_file,line);
        //cout<<line<<endl;

        // Checking if the line is a comment
        vector<string> c_type;
        c_type.push_back("//");
        c_type.push_back(";");

        size_t found_c;
        size_t found = string::npos;
        for (int i=0; i<c_type.size(); i++ )
        {
            found_c = line.find(c_type[i]);
            found = min(found, found_c);
        }

        if ( found!=string::npos )
        {
            // If on position 0 the complete line is a comment
            if ( found == 0 ) continue;
            // If on position greater than 0, the last part of the line is dropped
            if ( found > 0 )
                line = line.substr(0,found-1);
        }

        // Checking if it is a block
        size_t found_q1, found_q2;
        found_q1 = line.find("[");
        found_q2 = line.find("]");
        if (found_q1  != string::npos )
        {
            cout<<"Found block: "<<line.substr(found_q1+1,found_q2-found_q1-1)<<endl;
        }
        // kill any white space present
        string::iterator end_pos = remove(line.begin(), line.end(), ' ');
        line.erase(end_pos, line.end());
        // Now line is a string without spaces that can be broken at the symbol '='

        // Aircraft geometry
        double val = 0;
        vector<double> pos(3,0);
        string name = "";

        // main wing
        name = "wing_area=";
        val = setValue(line, name);
        acft.wing[main_wing].setArea(val);

        name = "wing_span=";
        val = setValue(line, name);
        acft.wing[main_wing].setSpan(val);

        name = "wing_root_chord=";
        val = setValue(line, name);
        acft.wing[main_wing].setCroot(val);

        name = "wing_sweep=";
        val = setValue(line, name);
        acft.wing[main_wing].setSweep(val);

        name = "oswald_efficiency_factor=";
        val = setValue(line, name);
        acft.wing[main_wing].setOswald(val);

        name = "wing_pos_apex_lon=";
        pos[0] = setValue(line, name);
        name = "wing_pos_apex_vert=";
        pos[2] = setValue(line, name);
        acft.wing[main_wing].setPosition(pos);


        // tail
        name = "htail_area=";
        val = setValue(line, name);
        acft.wing[tail].setArea(val);

        name = "htail_span=";
        val = setValue(line, name);
        acft.wing[tail].setSpan(val);

        name = "htail_sweep=";
        val = setValue(line, name);
        acft.wing[tail].setSweep(val);

        name = "htail_pos_lon=";
        pos[0] = setValue(line, name);
        name = "htail_pos_vert=";
        pos[2] = setValue(line, name);
        acft.wing[tail].setPosition(pos);

        // rudder
        name = "vtail_area=";
        val = setValue(line, name);
        acft.wing[rudder].setArea(val);

        name = "vtail_span=";
        val = setValue(line, name);
        acft.wing[rudder].setSpan(val);

        name = "vtail_sweep=";
        val = setValue(line, name);
        acft.wing[rudder].setSweep(val);

        name = "vtail_pos_lon=";
        pos[0] = setValue(line, name);
        name = "vtail_pos_vert=";
        pos[2] = setValue(line, name);
        acft.wing[rudder].setPosition(pos);

        // datum_position
        name = "reference_datum_position=";
        val = setValue(line, name);
        acft.reference_datum_position = val;
    }

    return acft;
}


double setValue(string &line, string &name)
{
    double val = 0.0;

    size_t found_ew = line.find(name);
    if ( found_ew!=string::npos)
    {
        size_t found_s = line.find("="); // all lines are "name=values"
        line = line.substr(found_s+1,line.size()); // Isolating value after "="

        stringstream line_val;
        line_val<<line;
        line_val>>val;
        //cout<<name<<" "<<val<<endl;
    }
    return val;
}
