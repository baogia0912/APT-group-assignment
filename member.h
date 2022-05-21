#ifndef MEMBER_H
#define MEMBER_H
#include "house.h"
#include "account.h"
#include <iostream>
using namespace std;
class Member
{

private:
    int id;
    Account *acc;
    vector<House *> houses;
    vector<Rating *> ratings;
    int credits;
    double selfRating;

public:
    Member();
    Member(int id, string username, string password);
    Account getAccount();
    void setOccupierID(int ID, House *house);
    int getID();
    void setCPD(int num, House *targetHouse);
    void addHouse(House *house);
    vector<House*> Member::getAllHouses();
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
    friend ostream &operator<<(ostream &os, const Member &mem);
};

ostream& operator<<(ostream& os, const Member& mem)
{
    os << "Member ID : " << mem.id
       << "\nMember rating : " << mem.selfRating
       << "\nMember creadit : " << mem.credits;
    return os;
};

#endif
