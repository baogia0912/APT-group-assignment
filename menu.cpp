#include "login.cpp"
#include "database.cpp"
#include "guestSubMenu.cpp"
#include "adminSubMenu.cpp"
#include "memberSubMenu.cpp"
vector<House> houses;
vector<Admin> admins;
vector<Member> members;

string menuOption(string option)
{
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
    string option;
    option = menuOption(option);

    getAllData(&admins, &members, &houses);
    while (option == "1" || option == "2" || option == "3")
    {
        if (option == "1")
        {
            menuForGuest(logInAsGuest(), &members, &houses);
        }
        if (option == "2")
        {

            menuForMember(logInAsMember(members), &members, &houses);
        }
        if (option == "3")
        {

            menuForAdmin(logInAsAdmin(admins), &members, &houses);
            // Press any key to return the main menu
        }
        option = menuOption(option);
    }
    // Exit the program
    cout << "===================================================== \n";
    cout << "                \tPROGRAM ENDED \n";
    cout << "===================================================== \n";
    cout << "          Thank you so much for your love\n";
    writeAllData(&admins, &members);
    exit(0);
}
