#include "rating.h"
#include "period.h"
#include "request.h"
#include <vector>
#ifndef HOUSE_H
#define HOUSE_H
class House
{
private:
    vector<Period> availablePeriods;
    vector<Rating *> houseRating;
    vector<Rating> minOccupierRating;
    vector<Request *> requests;

public:
    string address;
    string houseID;
    string description;
    string occupierID;
    House();

    House(string ID, string address, string occupierID, string description, vector<Rating *> houseRating, vector<Rating> occupierRating,
          vector<Period> availablePeriods);

    void getHouseRating(Rating &rating);
    friend class Member;
    friend class Guest;
};

#endif