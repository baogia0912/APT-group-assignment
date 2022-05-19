#include "member.h"
#include "house.h"
#include <vector>
#ifndef ADMIN_H
#define ADMIN_H


class Admin
{
private:
    Account *account;

public:
    Admin();
    Admin(string username, string password);

    Account getAccount();

    void viewAllMember(vector<Member> memberList);

    void viewAllHouse(vector<House> houseList);
};





#endif