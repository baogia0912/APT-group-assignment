#include "login.cpp"
#include "database.cpp"
#include "guestSubMenu.cpp"
// #include "adminSubMenu.cpp"
// #include "memberSubMenu.cpp"
int option;
vector<House> houses;
vector<Admin> admins;
vector<Member> members;

int menuOption(int option) {
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
    cin >> option;
    return option;
}

void menu()
{
    

    getAllData(&admins,&members,&houses);
    while (1)
    {
        option = menuOption(option);
        switch (option)
        {

        case 1:
            menuForGuest(logInAsGuest(), &members, &houses);            
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
            writeAllData(&admins,&members);
            exit(0);
        }
    }
}
