#include <iostream>
#include "account.cpp"
using namespace std;
#include "rating.cpp"
#include <vector>
class Member
{

private:
    Account *acc;


public:
    Member(){};
    Member(string username, string password)
    {
        this->acc = new Account(username, password);
    }

    Account getAccount()
    {
        return *acc;
    }

    void createRating(House house)
    {
        string comment;
        double point;
        cout << "Please enter you comment";
        cin >> comment;
        cout << "Rating ";
        cin >> point;
        Rating *rate = new Rating(comment, point);
        house.houseRating.push_back(rate);
    }
};
