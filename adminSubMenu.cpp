#include "admin.h"
#ifndef OPTION
#define OPTION 0
#endif

// Menu for admin;
/*
Option 1: View all member;

Option 2: View all house;
*/

void menuForAdmin()
{
    int OPTION;
    cout << "===================================================== \n";
    cout << "              \t\tMENU  \n";
    cout << "===================================================== \n";
    cout << "                Enter your choice (1-2)\n";
    cout << endl;
    cout << "1: View the member.\n";
    cout << "2: View the house."<<endl;
    cout <<endl;
    cout <<"Press any key to exit the program"<<endl;
}