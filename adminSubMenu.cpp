#include "admin.h"

int adminOptions(int option)
{
    cout << "===================================================== \n";
    cout << "              \t\tMENU  \n";
    cout << "===================================================== \n";
    cout << "                Enter your choice (1-2)\n";
    cout << endl;
    cout << "1: View the member.\n";
    cout << "2: View the house." << endl;
    cout << endl;
    cout << "Press any key to exit the program" << endl;
    cin >> option;
    return option;
}

void menuForAdmin(Admin *admin, vector<Member> *members, vector<House> *houses)
{
    int option;
    while (1)
    {
        option = adminOptions(option);
        switch (option)
        {
        case 1:
            admin->viewAllHouse(houses);
            return;
            break;
        case 2:
            admin->viewAllMember(members);
            break;
        default:
            return;
        }
    }
}
