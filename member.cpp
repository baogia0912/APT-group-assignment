#include <iostream>

using namespace std;

class Member
{
private:
    string password;
    string username;
    string role = "member";

public:
    Member(){};
    Member(string username, string password)
    {
        this->username = username;
        this->password = password;
        this->role;
    }
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
};

