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
        if (username == mem.getAccount().username)
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
    Member* newMember = new Member(nextID(*members), username, password1);
    newMember->addCredit(500);
    members->push_back(*newMember);
    return newMember;
}

void Guest::viewHouseDetails(vector<House> houseList)
{

    for (House house : houseList)
    {
        cout << "House ID : " << house.houseID << endl;
        cout << "House Address : " << house.address << endl;
        cout << "Description : " << house.description << endl;
        cout << "Credit Per Day : " << house.CPD << endl;
    }
}
#endif // !GUEST_CPP
