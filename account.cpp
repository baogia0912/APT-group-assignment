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
    return this->password == password;
}
#endif