#include "house.h"
#include "account.cpp"
#include "period.cpp"
#include "request.cpp"
#include "rating.cpp"
#ifndef MEMBER_H
#define MEMBER_H

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
    double calculateSelfRating(vector<Rating *> ratings);
    void listAvailableHouse();
    void viewAllRequest(House *house);
    bool acceptRequest(House *house, Request *request);
    bool rateOccupier(Member *occupier);
    void searchHouse(string address);
    friend class Admin;
    friend ostream &operator<<(ostream &os, const Member &dt);
};

ostream &operator<<(ostream &os, const Member &dt)
{
    os << "Member ID : " << dt.id << endl
       << "Member rating : " << dt.selfRating << endl
       << "Member creadit : " << dt.credits << endl;
    return os;
};

#endif
