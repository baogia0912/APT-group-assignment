#include "account.cpp"
#include "rating.cpp"
#include "member.h"

Member::Member(){};
Member::Member(string id, string username, string password)
{
    this->id = id;
    this->acc = new Account(username, password);
}

Account Member::getAccount()
{
    return *acc;
}

string Member::getID(){
    return id;
    }

void Member::createRating(House *house)
{
    string comment;
    double point;
    cout << "Please enter you comment";
    cin >> comment;
    cout << "Rating ";
    cin >> point;
    Rating *rate = new Rating(comment, point);
    house->houseRating.push_back(rate);
}

