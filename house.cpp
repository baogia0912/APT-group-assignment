#include "house.h"

House::House()
{
}

House::House(string ID, string address, string occupierID, string description, vector<Rating *> houseRating, vector<Rating> occupierRating,
             vector<Period> availablePeriods)
{
    this->houseID = ID;
    this->address = address;
    this->occupierID = occupierID;
    this->description = description;
    this->houseRating = houseRating;
    this->minOccupierRating = occupierRating;
    this->availablePeriods = availablePeriods;
}

void House::getHouseRating(Rating &rating)
{
}
