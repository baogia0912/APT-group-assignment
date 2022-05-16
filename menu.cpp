#include <iostream>
#include <string>
using namespace std;

void menu() {
    int option;
    string username, password;

    cout << "This is the menu" << endl;
    cin >> option;

    switch (option) {
        case 1: 
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (logIn(username, password)) {

            }
            
        case 2: logInAsGuest();
    }
}