#include <iostream>
#include <string>
#include "guestSubMenu.cpp"
using namespace std;
#include <vector>
#include "member.cpp"
#include "admin.cpp"

class Menu
{
private:
    vector<Member *> memberList;
    vector<Admin *> adminList;
    vector<House *> houseList;

public:
    void menu()
    {
        int option;
        string username, password;

        cout << "This is the menu" << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter username: ";
            cin >> username;

            cout << "Enter password: ";
            cin >> password;

            // if (logIn(username, password)) {

            // }

        case 2: // Loginasguet()
                // If want to log in as member, turn to input for user member.
                //  If not agree, continue view as guest.
        }
    }
};



int main () {
    cout << "hello";
    
}