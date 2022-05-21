#include "guestSubMenu.cpp"
#include "memberSubMenu.cpp"
#include "adminSubMenu.cpp"
#include "logIn.cpp"
#include "database.cpp"

void menu()
{
    int option;
    vector<Member *> members;
    vector<Admin *> admins;
    vector<House *> houses;

    // auto data = getAllData(&admins, &members, &houses);

    int highestID = 0;
    for (Member *mem : members)
    {
        if (mem->getID() > highestID)
            highestID = mem->getID();
    }
    ++highestID;
#define NEXTMEMBERID highestID

    while (1)
    {
        cout << "===================================================== \n";
        cout << "              \t\tMENU \n";
        cout << "===================================================== \n";
        cout << "                Enter your choice (1-3)\n";
        cout << "1: Log in as a Guest";
        cout << "2: Log in as an Member";
        cout << "3: Log in as an Admin";
        cout << "Press any key to exit the program." << endl;
        cin >> option;

        switch (option)
        {
        case 1:
            menuForGuest(logInAsGuest(), members);
            break;
        case 2:
            if (logInAsMember(members))
                menuForMember();
            break;
        case 3:
            if (logInAsAdmin(admins))
                menuForAdmin();
            break;
        default:
            break;
        }
    }

    writeAllData(admins, members);
}
