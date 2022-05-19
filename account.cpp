#include <iostream>
using namespace std;
// #include "member.cpp"
// #include "admin.cpp"
// #include "functions.cpp"
class Account
{
private:
    string password;
    string username;
    string role = "member";

public:
    Account(){};
    Account(string username, string password)
    {
        this->username = username;
        this->password = password;
        this->role;
    };

    bool verifyPass(string password)
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
    friend class Admin;
    friend class Member;
};
