#ifndef HOUSE_CPP
#define HOUSE_CPP
#include "house.h"

House::House()
{
}

House::House(int houseID, string address,string description, int CPD) {
    this->houseID = houseID;
    this->address = address;
    this->description = description;
    this->CPD = CPD;
}

House::House(int houseID, string address, string description, int CPD, double minOccupierRating, int occupierID) {
    this->houseID = houseID;
    this->address = address;
    this->description = description;
    this->CPD = CPD;
    this->minOccupierRating = minOccupierRating;
    this->occupierID = occupierID;
    this->availablePeriods = availablePeriods;
    this->ratings = ratings;
    this->requests = requests;
}

vector<Period *> House::getPeriods(){
    return this->availablePeriods;
}
void House::setPeriods(vector<Period *> periods){
    this->availablePeriods = periods;
}
vector<Rating *> House::getRatings(){
    return this->ratings;
}
void House::setRatings(vector<Rating *> ratings){
    this->ratings = ratings;
}
vector<Request *> House::getRequests(){
    return this->requests;
}
void House::setRatings(vector<Request *> requests){
    this->requests = requests;
}

double House::getHouseAvgRating(){
    int count = 0;
    double sum = 0;
    for (Rating *rating : ratings) {
        sum += rating->getRating();
        count++;
    }
    return sum/count;
}
#endif // !HOUSE_CPP
