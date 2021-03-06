#include "member.h"
#include "ulimit.h"

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
         << "6: Request to occupy a house.\n"
         << "7: Add rating to the occupier.\n";
    cout << endl;
    cout << "Press any key to exit the program" << endl;
    cin >> option;
    return option;
}
//menu for the member
void menuForMember(int member_id, vector<Member> *members, vector<House> *houses)
{
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
                    cout << "Enter your house address" << endl;
                    cin >> address;
                    cout << "Enter the description" << endl;
                    cin >> descripion;
                    cout << "Enter the CPD" << endl;
                    cin >> CPD;
                    House *newHouse = new House(nextID(houses), address, descripion, CPD);
                    member->addHouse(newHouse);
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

                // enter house id  -> add rating for occupy
                if (option == "7")
                {
                    int id;
                    string comment;
                    double rating;
                    cout << "Enter house id of your occupied house " << endl;
                    cout << "Enter your comment for the occupier" << endl;
                    cin >> comment;
                    cout << "Enter the rate" << endl;
                    Rating *newRating = new Rating(rating, comment);
                    for (House house : *houses)
                    {
                        if (house.getHouseID() == id && house.getOccupierID())
                        {
                            for (Member member : *members)
                            {
                                if (house.getOccupierID() == member.getID())
                                {
                                    member.getRatings().push_back(newRating);
                                }
                            }
                        }
                    }
                }
                option = memberOptions(option);
            }
        }
    }
}
