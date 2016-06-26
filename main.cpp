#include <iostream>
#include <fstream>
#include <string>
#include "aircraft.h"
#include "isa.h"
#include "menu.h"
#include "parser.h"

using namespace std;

int main()
{
    cout<<" *** AICRAFT CG LIMITS ***"<<endl;
    ifstream ac_file;
    bool run = true;

    while (run)
    {
        choice uChoice = menu();

        switch (uChoice)
        {
                case readCfgFile:
                    {
                        cout<<"WRITE ABSOLUTE PATH TO aircraft.cfg: "<<endl;
                        string file_name;
                        getline(cin,file_name);
                        ac_file.open(file_name.c_str());
                        if (!ac_file.is_open())
                        {
                            cout<<"File \""<<file_name<<"\" not found"<<endl;
                            return 1;
                        }
                        parseCfgFile(ac_file);
                        break;
                    }
                case printISA:
                    {
                         ISA isa;
                         isa.print();
                         break;
                    }
                case quit:
                    {
                        run = false;
                        break;
                    }
                default:
                    cout<<"WRONG CHOICE. PLEASE MAKE ANOTHER ONE\n";
        }
    }

    cout<<" *** END ***"<<endl;


    ac_file.close();


    return 0;
}
