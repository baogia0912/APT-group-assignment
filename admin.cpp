

#include <iostream>
#include "account.cpp"
#include "functions.cpp"
using namespace std;

class Admin : public Account
{
private:
public:
    Admin(){};
    Admin(string username, string password) : Account(username, password){};
};