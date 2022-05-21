#ifndef MEMBER_H
#define MEMBER_H
#include "account.h"
#include "house.h"

class Member
{

private:
    int id;
    Account *acc;
    vector<House *> memberHouse;
    vector<Rating *> ratings;
    int credits;
    double selfRating;

public:
    Member();
    Member(string username, string password);
    Member(int id, string username, string password);
    Account getAccount();
    void setOccupierID(int ID, House *house);
    int getID();
    void setCPD(int num, House *targetHouse);
    void addHouse(House *house);
    void createHouseRating(House *house);
    void createRequest(House *house);
    void addCredit(int num);
    void housesListing();
    double CaluculateSelfRating(vector<Rating *> ratings);
    void listAvailableHouse();
    void viewAllRequest(House *house);
    bool acceptRequest(House *house, Request *request);
    bool rateOccupier(Member *occupier);
    void searchHouse(string address);
};

#endif
