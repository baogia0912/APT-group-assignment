#ifndef ADMIN_H
#define ADMIN_H
#include "member.h"
#include "house.h"
#include <iostream>
using namespace std;
class Admin
{
private:
    int id;
    Account account;

public:
    Admin();
    Admin(int id, string username, string password);

    Account getAccount();

    int getID();

    void viewAllMember(vector<Account *> memberList);

    void viewAllHouse(vector<House *> houseList);
    void viewAllRequest(vector<Request *> requestList);

    double getHouseRating(vector<Rating *> houseRating);
};

#endif