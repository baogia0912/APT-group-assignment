#include <stdio.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "member.cpp"
#include "admin.cpp"
#include "guest.cpp"

using namespace std;

class login
{
private:
    string username;
    string password;

public:
    login() {}
    login(string username, string password)
    {
        this->username = username;
        this->password = password;
    }

    bool logInAsGuest()
    {
        for (int i=0;i<=usernameGuestList.size();i++){
            if (this->username == usernameGuestList.at(i)){
                for (int j=0;j<=passwordGuestList.size();j++){
                    if(this->password==passwordGuestList.at(i)){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool logInAsMember()
    {
        for (int i = 0; i <= usernameMemberList.size(); i++)
        {
            if (this->username == usernameMemberList.at(i))
            {
                for (int j = 0; j < passwordMemberList.size(); j++)
                {
                    if (this->password == passwordMemberList.at(i))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool logInAsAdmin(vector<Admin> admins)
    {
        for (int i = 0; i <= usernameAdminList.size(); i++)
        {
            if (this->username == usernameAdminList.at(i))
            {
                for (int j = 0; j < passwordAdminList.size(); j++)
                {
                    if (this->password == passwordAdminList.at(j))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};