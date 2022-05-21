#ifndef HOUSE_H
#define HOUSE_H
#include "rating.h"
#include "period.h"
#include "request.h"

class House
{
private:
    vector<Period *> availablePeriods; // done
    vector<Rating *> houseRating;      // done
    double minOccupierRating;          // done
    vector<Request *> requests;        // done
    int CPD;

public:
    string address;     // done
    string houseID;     // done
    string description; // done
    int occupierID;     // done
    House();

    House(int houseID, string address, string description, int CPD);
    friend ostream &operator<<(ostream &os, const House &dt);
    double getHouseRating(Rating &rating);

    friend class Member;
    friend class Admin;
};

ostream &operator<<(ostream &os, const House &dt)
{
    os << "House ID : " << dt.houseID << endl
       << "House address : " << dt.address << endl
       << "Description : " << dt.description << endl
       << "Occupier ID : " << dt.occupierID << endl
       << "Occupier requirement rate : " << dt.minOccupierRating << endl
       << "CPD : " << dt.CPD << endl;
    return os;
};

#endif