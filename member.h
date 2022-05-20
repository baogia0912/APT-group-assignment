#ifndef MEMBER_H
#define MEMBER_H
#include "account.h"
#include "house.h"
class Member
{

private:
    string id;
    Account *acc;
    vector<House *> houses;
    vector<Request> requests;
    vector<Rating *> ratings;

public:
    Member();
    Member(string id, string username, string password);

    Account getAccount();
    string getID();
    
    void createRating(House *house);
};

#endif
