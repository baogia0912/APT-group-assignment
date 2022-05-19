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

    void viewAllMember(vector<Account *> memberList);

    void viewAllHouse(vector<House *> houseList);

    double getHouseRating(vector<Rating *> houseRating);

    double getOccupantRating(vector<Rating *> occupantRating);

    void getRequest(vector<Request *> requestList);
};

#endif