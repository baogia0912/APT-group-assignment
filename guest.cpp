#include <iostream>
using namespace std;
#include "member.cpp"
#include <vector>
#include "guest.h"
#include "functions.cpp"
Guest::Guest(){};
vector<string> passwordGuestList;
vector<string> usernameGuestList;

Member Guest::signUp(vector<Member> members)
{
    string username, password;
    cout << "Enter your username: " << endl;
    cin >> username;
    cout << "Enter your password: " << endl;
    cin >> password;
    cout << "Registration Completed. " << endl;
    Member *acc = new Member(username, password);
    acc->generateID(members);
    return *acc;
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



