#include "parser.h"

enum t_wing
{
    main_wing=0,
    tail=1,
    rudder=2
};

Aircraft parseCfgFile(ifstream &ac_file)
{
    // Block to parse:
    vector<string> name;
    name.push_back("wing_area");
    name.push_back("wing_span");
    name.push_back("wing_root_chord");
    name.push_back("wing_sweep");
    name.push_back("oswald_efficiency_factor");
    name.push_back("wing_pos_apex_lon");
    name.push_back("wing_pos_apex_vert");

    cout<<"PARSING AICRAFT.CFG"<<endl;
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
        //cout<<line<<endl; // uncomment for debugging
        // Lowering the line:
        toLower(line);
        // Checking if the line is a comment. If it is, ignore it and continue
        if ( !isCommentLine(line) )
        {
            // Checking if it is a block. If it is, lets look what there is inside.
            string block_name;
            bool is_block = isBlock(line, block_name);
            if (is_block)
            {
                cout<<"Found block: "<<block_name<<endl;
                // Examining block
                double val = 0;

                if ( block_name == "airplane_geometry" )
                {
                    for (int i=0; i<name.size(); i++)
                    {
                        string block_line;
                        getline(ac_file, block_line);
                        //cout<<block_line<<endl;
                        toLower(block_line);
                        //cout<<block_line<<endl;
                        cleanLine(block_line);
                        //cout<<block_line<<endl;
                        killWhiteSpaces(block_line);
                        // la ricerca deve essere fra tutti i valori di name[i]. L'ordine
                        // non e' noto
                        cout<<"..here.."<<block_line<<" "<<name[i]<<endl;
                        if (block_line == name[i])
                        {
                            val = setValue(block_line, name[i]);
                            cout<<val<<endl;
                            acft.wing[main_wing].set(name[i],val);
                        }
                    }
                }
            }
        }
    }

acft.print();

    return acft;
}

bool isBlock(string &line, string &block_name)
{
    size_t found_q1, found_q2;
    found_q1 = line.find("[");
    found_q2 = line.find("]");
    block_name = line.substr(found_q1+1,found_q2-found_q1-1);
    if (found_q1  != string::npos )
    {
        block_name = line.substr(found_q1+1,found_q2-found_q1-1);
        return true;
    }

    block_name = "";
    return false;
}

bool isCommentLine(string &line)
{
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
        if ( found == 0 ) return true;
        // If on position greater than 0, the last part of the line is dropped
        if ( found > 0 )    line = line.substr(0,found-1);
    }

    return false;
}


void cleanLine(string &line)
{
    // Remove trailing comments
    size_t found_c;
    size_t found = string::npos;
    for (int i=0; i<c_type.size(); i++ )
    {
        found_c = line.find(c_type[i]);
        found = min(found, found_c);
    }

    if ( found!=string::npos )
    {
        // If on position greater than 0, the last part of the line is dropped
        if ( found > 0 )    line = line.substr(0,found-1);
    }
}

void toLower(string &line)
{
    transform(line.begin(), line.end(), line.begin(), ::tolower);
}

void killWhiteSpaces(string &line)
{
    // kill any white space present
    string::iterator end_pos = remove(line.begin(), line.end(), ' ');
    line.erase(end_pos, line.end());
    // Now line is a string without spaces that can be broken at the symbol '='
}

double setValue2(string &line, string &name)
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

double setValue(string &line, string &name)
{
    double val = 0.0;
    string new_name = name + "="; // new_name stores "name="
cout<<new_name<<endl;
    size_t found_ew = line.find(new_name);
    cout<<line<<endl;
    if ( found_ew!=string::npos)
    {
        size_t found_s = line.find("="); // all lines are "name=value"
        line = line.substr(found_s+1,line.size()); // Isolating value after "="

        stringstream line_val;
        line_val<<line;
        line_val>>val;
        cout<<new_name<<" "<<val<<endl;
        return val;
    }
    return val;
}
