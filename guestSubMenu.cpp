#include <iostream>
using namespace std;

// Menu for guest;
/*
Option 1: Guest require to be a member;

Option 2: Guest continue viewing house design.
*/

void menuForGuest()
{
    int option;
    cout << "===================================================== \n";
    cout << "              \t\tMENU  \n";
    cout << "===================================================== \n";
    cout << "                Enter your choice (1-2)\n";
    cout << endl;
    cout << "1: Register a member account.\n"
         << "2: View all house details.\n";
    cout << "========================================================================= \n";
    cout << "  In case you would like to access the reviews section and avaiability.\n"
         << "              Member registration is compulsory" << endl;
    cout << "========================================================================= \n";
    cin >> option;

    switch (option)
    {
    case 1:
        registerMember();
        break;
    case 2:
        viewAllHouses();
        break;
    default:
        break;
    }
}
int main(){
    menuForGuest();
}