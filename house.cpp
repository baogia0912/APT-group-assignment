#include "house.h"

House::House()
{
}

House::House(int houseID, string address, string occupantID, string description, double minOccupierRating,
        vector<Rating *> houseRating, vector<Rating*> occupierRating, vector<Request*> requests, vector<Period*> availablePeriods){
    this->houseID = houseID;
    this->address = address;
    this->occupantID = occupantID;
    this->description = description;
    this->minOccupierRating = minOccupierRating;
    this->houseRating = houseRating;
    this->occupierRating = occupierRating;
    this->availablePeriods = availablePeriods;
    this->requests = requests;
}

ostream& operator<<(ostream& os, const House& house)
{
    os <<"House ID : " << house.houseID  << "\n" << 
    "House address : " <<  house.address << "\n" <<
    "Description : " << house.description << "\n" <<
    "Occupant ID : "<< house.occupantID;
    return os;
}


double House::getHouseRating(Rating &rating)
{
}
