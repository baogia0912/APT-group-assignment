#ifndef HOUSE_H
#define HOUSE_H
#include "rating.h"
#include "period.h"
#include "request.h"

class House
{
private:
    vector<Period*> availablePeriods;//done
    vector<Rating*> houseRating;//done
    vector<Rating*> occupierRating;//done
    double minOccupierRating;//done
    vector<Request*> requests;//done

public:
    string address;//done
    string houseID;//done
    string description;//done
    string occupantID;//done
    House();

    House(int houseID, string address, string occupantID, string description, double minOccupierRating,
        vector<Rating *> houseRating, vector<Rating*> occupierRating, vector<Request*> requests, vector<Period*> availablePeriods);

    double getHouseRating();
    friend class Member;
    friend class Guest;
    friend class Admin;
};

#endif