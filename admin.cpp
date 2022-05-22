#include "admin.h"
#include "account.cpp"

Admin::Admin() {}

Admin::Admin(int id, string username, string password)
{
    this->id = id;
    this->account = Account(username, password);
}

Account Admin::getAccount()
{
    return this->account;
}

int Admin::getID()
{
    return this->id;
}

void Admin::viewAllMember(vector<Member> *members)
{
    //overloading to_string function
    for (Member member : *members) cout << member;
}

void Admin::viewAllHouse(vector<House> *houseList)
{
    //overloading to_string function
    for (House house: *houseList) cout << house;
}
