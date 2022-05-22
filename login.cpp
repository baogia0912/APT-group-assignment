#include "guest.cpp"
#include "admin.h"
using namespace std;

Guest *logInAsGuest()
{
    return new Guest();
}
//login as member
int logInAsMember(vector<Member> members)
{
    Member *member;
    string userName;
    string password;
    cout << "Enter Username : " << endl;
    cin >> userName;

    for (Member mem : members)
    {   
        if (userName == mem.getAccount().getUsername()) {
            member = &mem;
            cout << "Enter password : " << endl;
            cin >> password;
            if (member->getAccount().verifyPass(password)) {
                return member->getID();
            }
            else
                return 0;
        }
    }
    return 0;
}
//log in as admin 
Admin *logInAsAdmin(vector<Admin> admins)
{        

    Admin *admin;
    string userName;
    string password;
    cout << "Enter Username : " << endl;
    cin >> userName;
    for (Admin ad : admins)
    {
        if (userName == ad.getAccount().getUsername())
            admin = &ad;
    }
    if (admin == nullptr)
        return admin;

    cout << "Enter password : " << endl;
    cin >> password;
    if (admin->getAccount().verifyPass(password))
        return admin;
    else
        return nullptr;
}
