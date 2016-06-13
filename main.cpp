#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <locale>
#include "aircraft.h"
#include "isa.h"

using namespace std;

int main()
{
    cout<<" *** AICRAFT CG LIMITS ***"<<endl;

    ifstream ac_file;
    string file_name = "./aircraft.cfg";
    ac_file.open(file_name.c_str());
    if (!ac_file.is_open())
    {
        cout<<"File \""<<file_name<<"\" not found"<<endl;
        return 1;
    }

    // Parsing aircraft.cfg
    string line;

    while (!ac_file.eof())
    {
        // reading line
        getline(ac_file,line);

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
        //out<<line<<endl;
        string::iterator end_pos = remove(line.begin(), line.end(), ' ');
        line.erase(end_pos, line.end());



        // Empty weight
        size_t found_ew = line.find("empty_weight=");
        if ( found_ew!=string::npos )
        {
            stringstream ss;
            double ew = 0.0;

            cout<<line<<endl;
            ss << line.substr(13,line.size());
            ss>>ew;
            cout<<"ew "<<ew<<endl;
        }
    }

    cout<<" *** END ***"<<endl;


    ac_file.close();

    class aircraft;

    ISA isa;
    isa.print();


    return 0;
}
