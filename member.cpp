#include "account.cpp"
#include "rating.cpp"
#include "member.h"








Member::Member(){};
Member::Member(string username, string password)
{
    this->acc = new Account(username, password);
}

Account Member::getAccount()
{
    return *acc;
}

int Member::getID(){
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


void Member::generateID(vector<Member> members) {
    int highestID = 0;
    for (Member mem : members) {
        if (mem.getID() > highestID) highestID = mem.getID();
    }
    this->id = ++highestID;
}
