#include "member.h"

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
        Score the occupied house.
        Comment the Occuppied house.

*/

void menuForMember()
{
    {
        cout << "===================================================== \n";
        cout << "              \t\tMENU \n";
        cout << "===================================================== \n";
        cout << "                Enter your choice (1-5)\n";
        cout << endl;
        cout << "1: Viewing your Information.\n"
             << "2: Listing the Available house for being occupied.\n"
             << "3: Search the available houses.\n"
             << "4: View the listed houses.\n"
             << "5: View the House Occupied.\n";
        cout <<endl;
        cout <<"Press any key to exit the program"<<endl;
        cin >> OPTION;
        switch (OPTION)
        {
        case 1:
            // viewAllHouse();
            break;
        case 2:
            // viewOpcupiedHouse();
            break;
        case 3:
            // Viewing the Available house
            // listAvailableHouse();
            int optionCase3;
            cout << "Enter your choice(1-2)" << endl;
            cout << "1: View the house and request to occupy.\n";
            cout << "2: View the house only." << endl;
            cin >> optionCase3;
            switch (optionCase3)
            {
            case 1:
                break;
            case 2:
                break;
            default:
                break;
            }
            break;
        case 4:
            // viewListedHouse();
            int optionCase4;
            cout << "Enter your choice(1-2)";
            cout << "1: View the requets and accept.";
            cout << "2: View the requets only.";
            cin >> optionCase4;
            switch (optionCase4)
            {
            case 1:

                break;
            case 2:

                break;
            default:
                break;
            }
            break;
        case 5:
            // viewHouseOccupy();
            int optionCase5;
            cout << "Enter your choice(1-2)";
            cout << "1: Score the house occupied.";
            cout << "2: Comment the house occupied.";
            cin >> optionCase5;
            switch (optionCase5)
            {
            case 1:

                break;
            case 2:

                break;
            default:
                break;
            }
            break;

        default:
            exit(0);
            break;
        }
    }
}
