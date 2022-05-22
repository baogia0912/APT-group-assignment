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

int Member::getCreadit()
{
    return this->credits;
};
vector<Rating *> Member::getRating()
{
    return this->ratings;
};

int Member::getID()
{
    return id;
}

void Member::addHouse(House *house)
{
    this->houses.push_back(house);
}

vector<House *> Member::getAllHouses()
{
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

bool Member::createHouseRating(House *house)
{
    if (house != nullptr && house->occupierID == this->id)
    {
        string comment;
        double points;
        cout << "Please enter your comment";
        cin >> comment;
        cout << "Rating(-10 -> +10): ";
        cin >> points;
        if (points < -10 || points > 10)
            return false;
        house->getRatings().push_back(new Rating(points, comment));
        return true;
    }
    return false;
}

bool Member::rateOccupier(Member *occupier)
{
    for (House *house : this->houses)
    {
        if (occupier != nullptr && house->occupierID == occupier->getID())
        {
            double points;
            string comment;
            cout << "Please enter your comment: ";
            cin >> comment;
            cout << "Rating(-10 -> +10): ";
            cin >> points;
            if (points < -10 || points > 10)
                return false;
            Rating *rate = new Rating(points, comment);
            occupier->ratings.push_back(rate);
            return true;
        }
    }
    return false;
}

void Member::createRequest(House *house)
{
    // ask for start date and end date here
    Period period;
    // Period period(startDate, endDate);
    cout << "Enter your ID";
    house->getRequests().push_back(new Request(this->id, period));
}

double Member::getAverageSelfRating(vector<Rating *> ratings)
{
    double points;
    for (Rating *rate : ratings)
    {
        points += rate->getRating();
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
    for (Request *request : house->getRequests())
    {
        cout << "Requester ID : " << request->getRequesterID();
        cout << "Period : "
             << "from" << request->getPeriod().getStartDate()
             << " to " << request->getPeriod().getEndDate() << endl;
    }
}

bool Member::acceptRequest(House *house, Request *request)
{
    if (!house->occupierID)
    {
        house->occupierID = request->getRequesterID();
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
