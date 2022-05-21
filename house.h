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
    int occupierID;  // done
    House();

    House(int houseID, string address,string description, int CPD);
    friend ostream &operator<<(ostream &os, const House &dt);
    double getHouseRating(Rating &rating);
    friend class Member;
    friend class Guest; // sua lai
    friend class Admin;
};

#endif