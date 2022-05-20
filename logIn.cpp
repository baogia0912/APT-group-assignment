#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "member.cpp"
#include "admin.cpp"
#include "guest.cpp"

using namespace std;

bool logInAsGuest()
{
}

Member *logInAsMember(vector<Member *> members)
{
    Member *member;
    string userName;
    string password;
    cout << "Enter Username : " << endl;
    cin >> userName;

    for (Member *mem : members)
    {
        if (userName != mem->getAccount().username)
            return nullptr;
        else
            member = mem;
    }
    cout << "Enter password : " << endl;
    cin >> password;
    if (member->getAccount().verifyPass(password))
        return member;
    else
        return nullptr;
}

bool logInAsAdmin(vector<Admin *> admins)
{
}
