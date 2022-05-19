#include <iostream>
using namespace std;
#include "member.h"
#include "admin.h"
#include <vector>
#include "house.h"
#include "account.cpp"


    Admin::Admin(){};
    Admin::Admin(string username, string password){
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
