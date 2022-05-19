#include <iostream>
using namespace std;

// Menu for member;
/*
Option 1: View them information.
Option 2: List the available house for being occupied.
Option 3: Search all available house
        Request to occupy a house
Option 4: View the listed house.
        Accept a request.
        Or no.
Option 5: View the house occupy.
        Socre the occupied house.
        Comment the Occuppied house.

*/

void menuForGuest()
{
    int option;
    {
        cout << "===================================================== \n";
        cout << "              \t\tMENU \t \t \n";
        cout << "===================================================== \n";
        cout <<"                Enter your choice (1-5)\n";
        cout << endl;
        cout << "1: Viewing your Information.\n"
             << "2: Listing the Available house for being occupied.\n"
             << "3: Search the available houses.\n"
             << "4: View the listed houses.\n"
             << "5: View the House Occupied" << endl;
        cin >> option;
        switch (option)
        {
        case 1:
            // viewAllHouse();
            break;
        case 2:
            // viewOpcupiedHouse();
            break;
        case 3:
            // Viewing the Available house
            // viewAvailableHouse();
            break;
        case 4:
            // viewListedHouse();
            break;
        case 5:
            // viewHouseOccupy();
            break;

        default:
            break;
        }
    }
}
// menuForGuest();
int main(){
    menuForGuest();
}