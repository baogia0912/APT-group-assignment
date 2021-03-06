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
vector<Rating *> Member::getRatings()
{
    return this->ratings;
};

int Member::getID()
{
    return this->id;
}

void Member::addHouse(House *house)
{
    this->houses.push_back(house);
}

vector<House *> Member::getAllHouses()
{
    return this->houses;
}

void Member::addhouse (House *house) {
    this->houses.push_back(house);

}

// create the rating for house
bool Member::createHouseRating(House *house)
{
    if (house != nullptr && house->getOccupierID() == this->id)
    {
        string comment;
        double points;
        cout << "Please enter your comment";
        cin >> comment;
        cout << "Rating(-10 -> +10): ";
        cin >> points;
        if (points < -10 || points > 10)
            return false;
        house->getRatings()->push_back(new Rating(points, comment));
        return true;
    }
    return false;
}
// rate the occupier
bool Member::rateOccupier(Member *occupier)
{
    for (House *house : this->houses)
    {
        if (occupier != nullptr && house->getOccupierID() == occupier->getID())
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
//create request
void Member::createRequest(House *house)
{
    // ask for start date and end date here
    Period period;
    // Period period(startDate, endDate);
    cout << "Enter your ID";
    house->getRequests()->push_back(new Request(this->id, period));
}

//calculate his/her own average points from the rating list
double Member::getAverageSelfRating()
{
    double points;
    for (Rating *rate : ratings)
    {
        points += rate->getRating();
    }
    return points / ratings.size();
}
//ad create dit when first signUp
void Member::addCredit(int num)
{
    this->credits = num;
};

//list all the house that are available to occupy
void Member::listAvailableHouse()
{
    for (House *house : this->houses)
    {
        cout << "CPD :" << house->getCPD() << endl;
        cout << "Min Rating requirement : " << house->getMinOccupierRating() << endl;
    }
};

//view all the house request
void Member::viewAllRequest(House *house)
{
    for (Request *request : (*house->getRequests()))
    {
        cout << "Requester ID : " << request->getRequesterID() << endl;
        cout << "Period : "
             << "from " << request->getPeriod().getStartDate() << endl
             << " to " << request->getPeriod().getEndDate() << endl;
    }
}
//accept the request from another member through the request list
bool Member::acceptRequest(House *house, Request *request)
{
    if (!house->getOccupierID())
    {
        for (int i = 0; i < house->overloadGetRequests().size(); i++)
        {
            if (request != house->overloadGetRequests()[i])
            {
                house->overloadGetRequests().erase(house->overloadGetRequests().begin(), house->overloadGetRequests().begin() + i);
                house->setOccupierID(request->getRequesterID());
            }
        }
    }
    return true;
}
//search the suitable house from the address
void Member::searchHouse(string address)
{
    cout << "Available Houses : " << endl;
    for (House *house : this->houses)
    {
        if (address == house->getAddress() && this->credits == house->getCPD() && this->selfRating == house->getMinOccupierRating())
        {
            cout << "House ID : " << house->getHouseID() << endl;
            cout << "house address : " << house->getAddress() << endl;
        }
    }
}

#endif
