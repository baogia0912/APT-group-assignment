#include <iostream>
#include <string.h>
using namespace std;
#include <member.cpp>
#include <vector>
class guest
{
private:
public:
    guest(){};

    Member signUp()
    {
        string userName, passWord;
        cout << "Enter your username: " << endl;
        cin >> userName;
        cout << "Enter your password: " << endl;
        cin >> passWord;
        cout << "Registration Completed. " << endl;
        Member *acc = new Member(userName, passWord);
        return *acc;
    }

    void viewLimitedHouse(vector<House>houseList)
    {
        
    }
};
