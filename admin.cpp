

#include <iostream>
#include "account.cpp"
using namespace std;

class Admin {
private:
    Account *account;
public:
    Admin(){};
    Admin(string username, string password){
        this->account = new Account(username,password);
    };

    Account getAccount () {
        return *account;
    }
};


