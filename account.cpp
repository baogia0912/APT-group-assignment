#ifndef ACCOUNT_CPP
#define ACCOUNT_CPP
#include "account.h"

Account::Account(){};
Account::Account(string username, string password)
{
    this->username = username;
    this->password = password;
};

string Account::getPassword() {
    return this->password;
}
string Account::getUsername() {
    return this->username;
}
void Account::setUsername(string username) {
    this->username = username;
}

bool Account::verifyPass(string password)
{
    return this->password == password;
}

#endif