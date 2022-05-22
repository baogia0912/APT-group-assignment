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
    string username;

public:

    Account();
    Account(string username, string password);

    string getPassword();
    string getUsername();
    void setUsername(string username);

    bool verifyPass(string password);
    friend class Admin;
    friend class Member;
    friend void writeAllData(vector<Admin> *adminList, vector<Member> *memberList);
};

#endif