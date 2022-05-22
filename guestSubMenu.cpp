#include "guest.cpp"

string guestOptions(string option) {
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

void menuForGuest(Guest* guest, vector<Member>* members, vector<House>* houses) {
    string option;
    option = guestOptions(option);

    while(option == "1" || option == "2") {

        if (option == "1") {
            if (guest->signUp(members) != nullptr) break;
        }
        if (option == "2") {
            guest->viewHouseDetails(*houses);
        }
        option = guestOptions(option);
    }
}