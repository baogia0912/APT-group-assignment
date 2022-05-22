#include "guest.cpp"
#include "admin.h"
using namespace std;

Guest *logInAsGuest()
{
    return new Guest();
}

// Member* logInAsMember(vector<Member *> members)
// {
//     Member *member;
//     string userName;
//     string password;
//     cout << "Enter Username : " << endl;
//     cin >> userName;

//     for (Member *mem : members)
//     {
//         if (userName == mem->getAccount().username) member = mem;
//     }
//     if (member == nullptr) return member;

//     cout << "Enter password : " << endl;
//     cin >> password;

//     if (member->getAccount().verifyPass(password))
//         return member;
//     else
//         return nullptr;
// }

Admin *logInAsAdmin(vector<Admin> admins)
{
    Admin *admin;
    string userName;
    string password;
    cout << "Enter Username : " << endl;
    cin >> userName;
    for (Admin ad : admins)
    {
        if (userName == ad.getAccount().username)
            *admin = ad;
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
