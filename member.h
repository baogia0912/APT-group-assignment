#include <iostream>
#include "account.h"
#include "house.h"
using namespace std;
#ifndef MEMBER_H
#define MEMBER_H
class Member
{

private:
    Account *acc;

public:
    Member();
    Member(string username, string password);

    Account getAccount();
    
    void createRating(House house);
};

#endif
