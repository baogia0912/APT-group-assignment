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
         << "2: Add a house.\n"
         << "3: Search the suitable houses.\n"
         << "4: Rate the House Occupied.\n"
         << "5: View request of a house you own.\n"
         << "6: Request to occupy a house.\n";
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
                    cout << *member << endl;
                }

                if (option == "2")
                {
                    // member->listAvailableHouse();
                }
                if (option == "3")
                {   
                    string address;
                    cout << "Enter a city you wanna search in: " << endl;
                    cin >> address;
                    for (House house : *houses) {
                        if (address == house.getAddress() && house.getCPD() < member->getCreadit() 
                            && house.getMinOccupierRating() < member->getAverageSelfRating())
                            cout << house << endl;
                    }
                }
                if (option == "4")
                {
                    for (House house : *houses) {
                        if (house.getOccupierID() == member->getID()) {
                            
                        }
                    }
                }
                if (option == "5")
                {
                    int houseID;
                    cout << "Enter the house id of the house you want to view requests: " << endl;
                    cin >> houseID;
                    for (House *house : member->getAllHouses()) {
                        if (house->getHouseID() == houseID) {
                            cout << "Here are the requests for your house with id: " << houseID << endl;
                            for (Request *request: *house->getRequests()){
                                cout << request << endl;
                            }
                        }
                    }
                }
                option = memberOptions(option);                
            }
        }
        break;
    }
}
