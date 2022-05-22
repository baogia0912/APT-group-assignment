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
    double getAverageSelfRating();
    void listAvailableHouse();
    void viewAllRequest(House *house);
    bool acceptRequest(House *house, Request *request);
    bool rateOccupier(Member *occupier);
    void searchHouse(string address);
    int getCreadit();
    vector <Rating*> getRatings();
    void viewPersonalInformation();

    friend ostream &operator<<(ostream &os, const Member &mem);
};

ostream& operator<<(ostream& os, const Member& mem)
{
    os  << "Member ID : " << mem.id << endl
        << "Member rating : " << mem.selfRating << endl
        << "Member creadit : " << mem.credits << endl
        << "Username : " << mem.acc->getUsername() << endl
        << "Password : " << mem.acc->getPassword() << endl;
        for (Rating *rating : mem.ratings) os << *rating << endl;
        for (House *house : mem.houses) os << *house << endl;
    return os;
};

#endif
