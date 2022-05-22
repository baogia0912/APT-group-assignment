#include "admin.h"

string adminOptions(string option)
{
    cout << "===================================================== \n";
    cout << "              \t\tMENU  \n";
    cout << "===================================================== \n";
    cout << "                Enter your choice (1-2)\n";
    cout << endl;
    cout << "1: View the member.\n";
    cout << "2: View the house." << endl;
    cout << endl;
    cout << "Press any key to return to main menu" << endl;
    cin >> option;
    return option;
}

void menuForAdmin(Admin *admin, vector<Member> *members, vector<House> *houses)
{
    if (admin == nullptr) {
        cout << "Failed to login!" << endl;
        return;
    }

    string option;
    option = adminOptions(option);
    while (option == "1" || option == "2")
    {
        if (option == "1")
        {
            admin->viewAllMember(members);
        }
        if (option == "2")
        {
            admin->viewAllHouse(houses);
        }
        option = adminOptions(option);
    }
}
