#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <locale>
#include "aircraft.h"
#include "isa.h"
#include "menu.h"

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
                        string file_name = "./aircraft.cfg";
                        ac_file.open(file_name.c_str());
                        if (!ac_file.is_open())
                        {
                            cout<<"File \""<<file_name<<"\" not found"<<endl;
                            return 1;
                        }
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
