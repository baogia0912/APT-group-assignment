#include <iostream>
#include "account.cpp"
using namespace std;
// #include "functions.cpp"

class Member : public Account
{

private:
public:
    Member():Account(){};
    Member(string username, string password) : Account(username, password){};
};