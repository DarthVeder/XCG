#include <iostream>
#include <fstream>
#include <string>
#include "aircraft.h"
#include "isa.h"
#include "menu.h"
#include "parser.h"
#include "aircraft.h"

using namespace std;

int main()
{
    cout<<" *** AICRAFT CG LIMITS ***"<<endl;
    ifstream ac_file;
    bool run = true;

    while (run)
    {
        Aircraft acft;
        choice uChoice = menu();

        switch (uChoice)
        {
                case READFILE:
                    {
                        cout<<"WRITE ABSOLUTE PATH TO aircraft.cfg: "<<endl;
                        string file_name;
                        //getline(cin,file_name);
                        file_name="C:\\home\\marco\\Work\\Flight Dynamics\\B350\\CG\\XCG\\bin\\Debug\\aircraft.cfg";
                        ac_file.open(file_name.c_str());
                        if (!ac_file.is_open())
                        {
                            cout<<"File \""<<file_name<<"\" not found"<<endl;
                            return 1;
                        }
                        acft = parseCfgFile(ac_file);
                        acft.computeData();
                        acft.print();

                        ac_file.close();
                        break;
                    }
                case PRINTISA:
                    {
                         ISA isa;
                         isa.print();
                         break;
                    }
                case QUIT:
                    {
                        run = false;
                        break;
                    }
                default:
                    cout<<"WRONG CHOICE. PLEASE MAKE ANOTHER ONE\n";
        }
    }

    cout<<" *** END ***"<<endl;

    return 0;
}
