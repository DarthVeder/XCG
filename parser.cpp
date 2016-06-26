 #include "parser.h"

Aircraft parseCfgFile(ifstream &ac_file)
{
    Aircraft acft;
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

        // Empty weight
        size_t found_ew = line.find("empty_weight=");
        if ( found_ew!=string::npos )
        {
            size_t found_s = line.find("=");
            line = line.substr(found_s+1,line.size());

            stringstream line_val;
            line_val<<line;
            double val;
            line_val>>val;
            cout<<val<<endl;
        }
    }

    return acft;
}
