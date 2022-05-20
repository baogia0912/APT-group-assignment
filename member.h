#ifndef MEMBER_H
#define MEMBER_H
#include "account.h"
#include "house.h"
class Member
{

private:
    string id;
    Account *acc;

public:
    Member();
    Member(string id, string username, string password);

    Account getAccount();
    string getID();
    
    void createRating(House house);
    friend void writeAllData(vector<Admin> adminList, vector<Member> memberList);
};

#endif
