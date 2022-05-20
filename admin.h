#ifndef ADMIN_H
#define ADMIN_H
#include "member.h"
#include "house.h"

class Admin
{
private:
    string id;
    Account *account;

public:
    Admin();
    Admin(string id, string username, string password);

    Account getAccount();

    void viewAllMember(vector<Member> memberList);

    void viewAllHouse(vector<House> houseList);
};





#endif