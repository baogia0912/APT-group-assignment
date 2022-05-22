#include "login.cpp"
#include "database.cpp"
#include "guestSubMenu.cpp"
#include "adminSubMenu.cpp"
// #include "memberSubMenu.cpp"
int option;
vector<House> houses ;
vector<Admin> admins;
vector<Member> members;

House house1 (5,"Binhthanh","nearCity",300);
Admin am (1,"owen1","123");
Member mem (2,"mai","54"); 
Admin am2 (7,"owen2","123");

Admin am3 (8,"owen3","123");

Admin am4 (9,"owen4","123");




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
    

    //getAllData(&admins,&members,&houses);
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
            houses.push_back(house1);
            members.push_back(mem);
            admins.push_back(am);
            admins.push_back(am2);
            admins.push_back(am3);
            admins.push_back(am4);

            menuForAdmin(logInAsAdmin(admins),&members,&houses);            
            break;
        default:
            // Exit the program
            cout << "===================================================== \n";
            cout << "                \tPROGRAM ENDED \n";
            cout << "===================================================== \n";
            cout << "          Thank you so much for your love\n";
            //writeAllData(&admins,&members);
            exit(0);
        }
    }
}
