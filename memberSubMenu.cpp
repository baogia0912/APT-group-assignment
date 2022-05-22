#include "member.h"
#include "ulimit.h"
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
    if (member_id == NULL)
    {
        cout << "Failed to login!" << endl;
        return;
    }
    Member *member;
    for (Member mem : *members)
    {
        if (mem.getID() == member_id)
        {
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
                { // add house
                    string address, descripion;
                    double CPD;
                    House *newHouse = new House(nextID(houses), address, descripion, CPD);
                    houses->push_back(*newHouse);
                }
                if (option == "3")
                { // search house;
                    string address;
                    cout << "Enter a city you wanna search in: " << endl;
                    cin >> address;
                    for (House house : *houses)
                    {
                        if (address == house.getAddress() && house.getCPD() < member->getCreadit() && house.getMinOccupierRating() < member->getAverageSelfRating())
                            cout << house << endl;
                    }
                }
                if (option == "6")
                {
                    // request house;
                    string startDate, endDate;
                    int houseID;
                    Period *tmpPeriod;
                    cout << "Enter house ID you want to request " << endl;
                    cin >> houseID;
                    cout << "Enter the start date" << endl;
                    cin >> startDate;
                    cout << "Enter the end date" << endl;
                    cin >> endDate;

                    tmpPeriod->setStartDate(startDate);
                    tmpPeriod->setEndDate(endDate);
                    for (int i = 0; i < houses->size(); i++)
                    {
                        if (houseID == (*houses)[i].getHouseID())
                        {
                            for (int j = 0; j < (*houses)[i].getPeriods()->size(); j++)
                            {
                                if ((*(*houses)[i].getPeriods())[j] == tmpPeriod)
                                {
                                    member->createRequest(&(*houses)[i]);
                                }
                            }
                        }
                    }
                }       
                if (option == "5")
                {
                
                    // view request
                    int id;
                    cout << "Enter ID of the house you want to view request " << endl;
                    cin >> id;
                    for (House house : *houses)
                    {
                        if (house.getHouseID() == id)
                        {
                            for (Request *request : *(house.getRequests()))
                                cout << request;
                        }
                    }
                }
                if (option == "4")
                {
                    // create rating
                    string comment;
                    double rating;
                    int id;
                    cout << "Choose the house ID " << endl;
                    cin >> id;
                    cout << "Enter your comment" << endl;
                    cin >> comment;
                    cout << "Enter your points" << endl;
                    cin >> rating;
                    Rating *newRating = new Rating(rating, comment);
                    for (House house : *houses)
                    {
                        if ((house.getOccupierID() == member->getID()) &&
                            house.getHouseID() == id)
                        {
                            house.getRatings()->push_back(newRating);
                        }
                    }
                }
            // enter house id  -> add rating for occupy 
            }
        }
    }
}
