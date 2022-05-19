#include <iostream>
#include "account.h"
#include "house.h"
#include <vector>
using namespace std;
#ifndef MEMBER_H
#define MEMBER_H
class Member
{

private:
    Account *acc;
    vector<House *> houses;
    vector<Request> requests;
    vector<Rating *> ratings;

public:
    Member();
    Member(string username, string password);

    Account getAccount();

    void createRating(House *house);
};

#endif
