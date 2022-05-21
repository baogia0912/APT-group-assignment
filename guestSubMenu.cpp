#include "guest.cpp"

int guestOptions(int option) {
    cout << "===================================================== \n";
    cout << "              \t\tMENU  \n";
    cout << "===================================================== \n";
    cout << "                Enter your choice (1-2)\n";
    cout << endl;
    cout << "       1: Register a member account.\n";
    cout << "       2: View all house details.\n";
    
    cout << endl;
    cout << "       Press any key to return to main menu.\n" << endl;
    cout << endl;

    cout << "========================================================================= \n";
    cout << "  In case you would like to access the reviews section and avaiability.\n"
         << "              Member registration is compulsory" << endl;
    cout << "========================================================================= \n";
    cin >> option;
    return option;
}

void menuForGuest(Guest* guest, vector<Member>* members) {
    int option;
    while(1) {
        option = guestOptions(option);
        switch (option)
        {
        case 1:
            if (guest->signUp(members) != nullptr) return;
            break;
        case 2:
            break;
        default:
            return;
        }
    }
}