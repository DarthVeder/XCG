#include "menu.h"

choice menu()
{
    cout<<" SELECT ONE OF THE FOLLOWING:"<<endl;
    cout<<READFILE<<" - LOAD AICRAFT.CFG"<<endl;
    cout<<PRINTISA<<" - PRINT ISA"<<endl;
    cout<<QUIT<<" - QUIT"<<endl;
    int val;
    cin>>val;
    choice t_choice = static_cast<choice>(val);

    string tmp;
    getline(cin,tmp);

    return t_choice;
}


