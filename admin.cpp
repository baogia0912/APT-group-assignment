

#include <iostream>
#include "account.cpp"
#include "adminSubMenu.cpp"
using namespace std;

class Admin {
private:
    Account *account;
public:

    friend class member;
    friend class guest;
    Admin(){};
    Admin(string username, string password){
        this->account = new Account(username,password);
    };

    Account getAccount () {
        return *account;
    }
    void adminViewAllHouse(){}
    void adminViewAllMember(){}

    }

};


