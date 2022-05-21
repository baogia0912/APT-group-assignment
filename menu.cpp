// #include "guestSubMenu.cpp"
// #include "memberSubMenu.cpp"
// #include "adminSubMenu.cpp"
// #include "logIn.cpp"
// #include "database.cpp"
using namespace std;
#include "iostream"

void menuOption()
{
    int option;
    cout << "===================================================== \n";
    cout << "              \t\tMENU \n";
    cout << "===================================================== \n";
    cout << "                Enter your choice (1-3)\n";
    cout << endl;
    cout << "               1: Log in as a Guest\n";
    cout << "               2: Log in as an Member\n";
    cout << "               3: Log in as an Admin\n";
    cout << endl;
    cout << "       Press any key to exit the program." << endl;
}
int menuOptionChoice()
{
    menuOption();
    int option;
    cin >> option;
    return option;
}
void menu()
{
    int option;

    //     vector<House > houses;
    //     vector<Admin > admins;
    //     vector<Member > members;

    //     getAllData(&admins,&members,&houses);

    //     int highestID = 0;
    //     for (Member mem : members)
    //     {
    //         if (mem.getID() > highestID)
    //             highestID = mem.getID();
    //     }
    //     ++highestID;
    // #define NEXTMEMBERID highestID

    while (1)
    {
        int option = menuOptionChoice();
        while (1)
        {

            switch (option)
            {
            case 1:
                // menuForGuest(logInAsGuest(), members);
                //  Press any key to return the main menu
                break;
            case 2:
                // if (logInAsMember(members))
                    //  menuForMember();
                // Press any key to return the main menu
                
                break;
            case 3:
                // if (logInAsAdmin(admins))
                    //  menuForAdmin();
                // Press any key to return the main menu
                
                break;
            default:
                // Exit the program
                cout << "===================================================== \n";
                cout << "                \tPROGRAM ENDED \n";
                cout << "===================================================== \n";
                cout << "          Thank you so much for your love\n";
                exit(0);
                break;
            }
        }
    }

    // writeAllData(admins,members);
}
