#include <iostream>
using namespace std;
#include "member.cpp"
#include <vector>
#include "guest.h"
#include "functions.cpp"
Guest::Guest(){};
vector<string> passwordGuestList;
vector<string> usernameGuestList;

Member* Guest::signUp(vector<Member*> members) {
    Member* newMember;
    string username;
    string password1;
    string password2;
    cout << "Enter Username: " << endl;
    cin >> username;

    for (Member *mem : members)
    {
        if (username == mem->getAccount().username) {
            cout << "This username is already existed! Please try sign up again." << endl;
            return nullptr;
        }
    }

    cout << "Enter password: " << endl;
    cin >> password1;

    cout << "Re-enter password: " << endl;
    cin >> password2;

    if (password1 != password2) {
        cout << "The 2 passwords you enter are different! Please try sign up again." << endl;
        return nullptr;
    }
    newMember = new Member(username, password1);
    members.push_back(newMember);
    return newMember;
}

void Guest::viewLimitedHouse(vector<House> houseList)
{
    for (int i = 0; i < houseList.size(); i++)
    {
        cout << "House id : " << houseList[i].houseID << endl;
        cout << "House address : " << houseList[i].address << endl;
        cout << "Description : " << houseList[i].description << endl;
        cout << endl;
    }
}



