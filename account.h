#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
using namespace std;
#include <vector>
class Admin;
class Member;

class Account
{
private:
    string password;

public:
    string username;

    Account();
    Account(string username, string password);

    bool verifyPass(string password);
    friend class Admin;
    friend class Member;
    friend void writeAllData(vector<Admin> *adminList, vector<Member> *memberList);
};

#endif