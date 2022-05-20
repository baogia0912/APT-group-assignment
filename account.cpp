#ifndef ACCOUNT_CPP
#define ACCOUNT_CPP
#include "account.h"

Account::Account(){};
Account::Account(string username, string password)
{
    this->username = username;
    this->password = password;
    // this->role;
};

bool Account::verifyPass(string password)
{

    if (password == this->password)
    {
        cout << "Correct password!" << endl;
        return true;
    }
    else
    {
        return false;
    }
}
#endif