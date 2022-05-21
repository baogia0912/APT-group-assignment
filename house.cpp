#include "house.h"

House::House()
{
}

House::House(int houseID, string address,string description, int CPD) {
    this->houseID = houseID;
    this->address = address;
    this->description = description;
}



double House::getHouseRating(Rating &rating)
{
}
