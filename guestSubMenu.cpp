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
    cout << "              \t\tMENU \t \t \n";
    cout << "===================================================== \n";
    cout << "                Enter your choice (1-5)\n";
    cout << endl;
    cout << "1: Register a member account.\n"
         << "2: View all house details.\n"

         << "In case you would like to access the reviews section and avaiability. Member registration is compulsory" << endl;
    cin >> option;

    switch (option)
    {
    case 1:
        // registerMember();
        break;
    case 2:
        // viewAllHouses();
        break;
    default:
        break;
    }
}
int main(){
    menuForGuest();
}