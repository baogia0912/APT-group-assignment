#include <iostream>
#include <string.h>
using namespace std;

class guest{

    private:
    string userName;
    string password;
    
    public:
    guest(){}

    guest(string userName, string password){
        this->userName=userName;
        this->password=password;
    }

    void logInAsGuest(){
        cout<<"Enter your username:";
        cin>>this->userName;
        cout<<"Enter your password:";
        cin>>this->password;
        cout<<"Registration Completed.";
    }
    void show_infor(){
        cout<<"Username: "<<userName
            <<" "
            <<"Password: "<<password<<endl;
    }
};
