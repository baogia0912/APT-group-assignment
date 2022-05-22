#ifndef GUEST_CPP
#define GUEST_CPP
#include "ultility.cpp"
#include "guest.h"

Guest::Guest(){};



Member *Guest::signUp(vector<Member>* members)
{
    string username;
    string password1;
    string password2;
    cout << "Enter Username: " << endl;
    cin >> username;

    for (Member mem : *members)
    {
        if (username == mem.getAccount().getUsername())
        {
            cout << "This username is already existed! Please try sign up again." << endl;
            return nullptr;
        }
    }

    cout << "Enter password: " << endl;
    cin >> password1;

    cout << "Re-enter password: " << endl;
    cin >> password2;

    if (password1 != password2)
    {
        cout << "The 2 passwords you enter are different! Please try sign up again." << endl;
        return nullptr;
    }
    //sign up a new member;
    Member* newMember = new Member(nextID(*members), username, password1);
    newMember->addCredit(500);
    members->push_back(*newMember);
    return newMember;
}
//allow guess to view house basic information 
void Guest::viewHouseDetails(vector<House> houseList)
{

    for (House house : houseList)
    {
        cout << "House ID : " << house.getHouseID() << endl;
        cout << "House Address : " << house.getAddress() << endl;
        cout << "Description : " << house.getDescription() << endl;
        cout << "Credit Per Day : " << house.getCPD() << endl;
        cout << endl;
    }
}
#endif // !GUEST_CPP
