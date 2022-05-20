#include <iostream>
using namespace std;
#include "member.cpp"
#include <vector>
#include "guest.h"
Guest::Guest(){};

Member Guest::signUp()
{
    string username, password;
    cout << "Enter your username: " << endl;
    cin >> username;
    cout << "Enter your password: " << endl;
    cin >> password;
    cout << "Registration Completed. " << endl;
    Member acc = Member(username, password);
    return acc;
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



