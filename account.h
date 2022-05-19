using namespace std;
#include <iostream>
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
private:
    string password;
    string username;

public:
    Account();
    Account(string username, string password);

    bool verifyPass(string password);
    friend class Admin;
    friend class Member;
};

#endif