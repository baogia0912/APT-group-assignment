#ifndef ADMIN_H
#define ADMIN_H
#include "member.cpp"
#include "house.h"
#include "account.cpp"


class Admin
{
private:
    int id;
    Account *account;

public:
    Admin();
    Admin(int id, string username, string password);

    Account getAccount();

    int getID();

    void viewAllMember(vector<Account *> memberList);
    void viewAllHouse(vector<House *> houseList);
};

#endif