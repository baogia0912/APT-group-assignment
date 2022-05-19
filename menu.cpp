#include <iostream>
#include <string>
#include "guestSubMenu.cpp"
#include "memberSubMenu.cpp"
#include "adminSubMenu.cpp"
#include "logIn.cpp"
using namespace std;


void menu() {
    int option;
    vector<Member> members;
    vector<Admin> admins;
    

    cout << "===================================================== \n";
    cout << "              \t\tMENU \n";
    cout << "===================================================== \n";
    cout << "                Enter your choice (1-5)\n";
    cout <<"1: Log in as a Guest";
    cout <<"2: Log in as an Member";
    cout <<"3: Log in as an Admin";
    cout <<"Press any key to exit the program."<<endl;
    cin >> option;

    switch (option)
    {
    case 1:
        if (logInAsGuest()) menuForGuest();
        break;
    case 2:
        if (logInAsMember(members))menuForMember();
        break;
    case 3:
        if (logInAsAdmin(admins))menuForAdmin();
        break;
    default:
        break;
    }

}

int main(){
    menu();
}