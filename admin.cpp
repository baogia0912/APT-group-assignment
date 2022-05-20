#include "admin.h"
#include "account.cpp"

Admin::Admin(){}

Admin::Admin(string id, string username, string password){
    this->id = id;
    this->account = new Account(username, password);
}

Account Admin::getAccount()
{
    return *account;
}

void Admin::viewAllMember(vector<Member> memberList)
{
    for (int i = 0; i < memberList.size(); i++)
    {
    }
}

void Admin::viewAllHouse(vector<House> houseList)
{
    for (int i = 0; i < houseList.size(); i++)
    {
    }
}
