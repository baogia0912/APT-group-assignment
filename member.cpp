#include "account.cpp"
#include "rating.cpp"
#include "member.h"
#include <vector>

vector<Member *> members;
vector<Admin *> admins;
vector<House *> houses;

Member::Member(){};
Member::Member(string username, string password)
{
#ifdef NEXTMEMBERID
    this->id = NEXTMEMBERID++;
#endif
    this->acc = new Account(username, password);
}
Member::Member(int id, string username, string password)
{
    this->id = id;
    this->acc = new Account(username, password);
}

Account Member::getAccount()
{
    return *acc;
}

int Member::getID()
{
    return id;
}

void Member::addHouse (House * house) {
    this->houses.push_back(house);
}

void Member::housesListing() {
    
    for (House * house : this->houses ) {
        if (house->availablePeriods.size() !=0) {
            cout <<"House " << house->address;
        }
    }
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

void Member::createRequest(House *house)
{
    int requesterId;    
    Period period;
    period.setPeriod();
    // Period period(startDate, endDate);
    cout << "Enter your ID";
    cin >> requesterId;
    Request *request = new Request(period, requesterId);
    for (House *target : houses)
    {
        if (target == house)
        {
            house->requests.push_back(request);
        }
    }
}

void Member::addCredit(int num)
{
    this->credits = num;
};