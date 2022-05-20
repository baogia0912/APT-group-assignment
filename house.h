#ifndef HOUSE_H
#define HOUSE_H
#include "rating.h"
#include "period.h"
#include "request.h"

class House
{
private:
    vector<Period*> availablePeriods;//done
    vector<Rating *> houseRating;//done
    vector<Rating*> minOccupierRating;//done
    vector<Request *> requests;//done

public:
    string address;//done
    string houseID;//done
    string description;//done
    string occupantID;//done
    House();

    House(string ID, string address, string occupantID, string description, vector<Rating *> houseRating, vector<Rating*> occupierRating,
          vector<Period*> availablePeriods);

    void getHouseRating(Rating &rating);
    friend class Member;
    friend class Guest;
    friend class Admin;
};

#endif