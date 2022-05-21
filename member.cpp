#ifndef MEMBER_CPP
#define MEMBER_CPP
#include "account.cpp"
#include "rating.cpp"
#include "member.h"
#include "period.cpp"
#include "request.cpp"

Member::Member(){};
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

void Member::addHouse(House *house)
{
    this->houses.push_back(house);
}

vector<House*> Member::getAllHouses() {
    return this->houses;
}

void Member::setCPD(int num, House *targetHouse)
{
    for (House *house : houses)
    {
        if (targetHouse == house)
        {
            house->CPD = num;
        }
        else
        {
            cout << "The house is not available";
            break;
        }
    }
}

void Member::housesListing()
{

    for (House *house : this->houses)
    {
        if (house->availablePeriods.size() != 0)
        {
            cout << "House " << house->address;
        }
    }
}

void Member::createHouseRating(House *house)
{
    if (house != nullptr)
    {
        string comment;
        double points;
        cout << "Please enter your comment";
        cin >> comment;
        cout << "Rating ";
        cin >> points;
        Rating *rate = new Rating(comment, points);
        house->houseRating.push_back(rate);
    }
}

bool Member::rateOccupier(Member *occupier)
{
    if (occupier == nullptr)
    {
        return false;
    }
    else
    {
        double points;
        string comment;
        cout << "Please enter your comment";
        cin >> comment;
        cout << "Rating";
        cin >> points;
        Rating *rate = new Rating(comment, points);
        occupier->ratings.push_back(rate);
    }
    return true;
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
    house->requests.push_back(request);
}

double Member::calculateSelfRating(vector<Rating *> ratings)
{
    double points;
    for (Rating *rate : ratings)
    {
        points += rate->rating;
    }
    this->selfRating = (points / ratings.size());
    return points;
}

void Member::addCredit(int num)
{
    this->credits = num;
};

void Member::listAvailableHouse()
{
    for (House *house : this->houses)
    {
        cout << "CPD :" << house->CPD << endl;
        cout << "Min Rating requirement : " << house->minOccupierRating << endl;
    }
};

void Member::viewAllRequest(House *house)
{
    for (Request *request : house->requests)
    {
        cout << "Requester ID : " << request->requesterID;
        cout << "Period : "
             << "from" << request->period.getStartDate()
             << " to " << request->period.getEndDate() << endl;
    }
}

bool Member::acceptRequest(House *house, Request *request)
{
    if (!house->occupierID)
    {
        house->occupierID = request->requesterID;
        return true;
    }
    return false;
}

void Member::searchHouse(string address)
{
    cout << "Available Houses : " << endl;
    for (House *house : this->houses)
    {
        if (address == house->address && this->credits == house->CPD && this->selfRating == house->minOccupierRating)
        {
            cout << "House ID : " << house->houseID << endl;
            cout << "house address : " << house->address << endl;
        }
    }
}


#endif
