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
string memberOptions(string option)
{
    cout << "===================================================== \n";
    cout << "              \t\tMENU \n";
    cout << "===================================================== \n";
    cout << "                Enter your choice (1-5)\n";
    cout << endl;
    cout << "1: View personal information.\n"
         << "2: Listing the Available house for being occupied.\n"
         << "3: Search the suitable houses.\n"
         << "4: Request to occupy a house.\n"
         << "5: View the House Occupied.\n";
    cout << endl;
    cout << "Press any key to exit the program" << endl;
    cin >> option;
    return option;
}

void menuForMember(int member_id, vector<Member> *members, vector<House> *houses)
{
    if (member_id == NULL) {
        cout << "Failed to login!" << endl;
        return;
    }
    Member * member;
    for (Member mem : *members) {
        if (mem.getID() == member_id) {
            member = &mem;
        

            string option;
            option = memberOptions(option);
            while (option == "1" || option == "2" || option == "3" || option == "4" ||
                option == "5")
            {
                if (option == "1")
                {
                    cout << *member;
                }

                if (option == "2")
                {
                    // member->listAvailableHouse();
                }
                if (option == "3")
                {
                    // string address;
                    // cout << "Enter an address";
                    // cin >> address;
                    // member->searchHouse(address);
                }
                if (option == "4")
                {

                    // member->createRequest();
                }
                if (option == "5")
                {
                }
                option = memberOptions(option);                
            }
        }
        break;
    }
}
