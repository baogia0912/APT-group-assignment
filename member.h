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
    int getID();
    void addHouse(House *house);
    vector<House*> getAllHouses();
    bool createHouseRating(House *house);
    void createRequest(House *house);
    void addCredit(int num);
    double getAverageSelfRating(vector<Rating *> ratings);
    void listAvailableHouse();
    void viewAllRequest(House *house);
    bool acceptRequest(House *house, Request *request);
    bool rateOccupier(Member *occupier);
    void searchHouse(string address);

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
