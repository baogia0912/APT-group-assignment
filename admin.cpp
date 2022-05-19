

#include <iostream>
#include "member.cpp"
using namespace std;

class Admin : public Member
{
private:
public:
    Admin(){};
    Admin(string username, string password) : Member(username, password){};
};