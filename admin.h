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

    void viewAllMember(vector<Account *> memberList);

    void viewAllHouse(vector<House *> houseList);

    double getHouseRating(vector<Rating *> houseRating);

    double getOccupantRating(vector<Rating *> occupantRating);

    void getRequest(vector<Request *> requestList);
};

#endif