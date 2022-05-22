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
    for (Member mem : *members)
    {
        mem.viewPersonalInformation();
    }
}

void Admin::viewAllHouse(vector<House> *houseList)
{
    Member *mem;
    for (House house : *houseList)
    {
        cout << house << endl;
        mem->viewAllRequest(&house);
        cout << endl;
    }
}
