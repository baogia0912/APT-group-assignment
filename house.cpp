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

double House::getMinOccupierRating() {
    return this->minOccupierRating;
}
void House::setMinOccupierRating(double minOccupierRating) {
    this->minOccupierRating = minOccupierRating;
}


string House::getAddress() {
    return this->address;
}
void House::setAddress(string address) {
    this->address = address;
}


string House::getHouseID() {
    return this->houseID;
}
void House::setHouseID(string houseID) {
    this->houseID = houseID;
}


string House::getDescription() {
    return this->description;
}
void House::setDescription(string description) {
    this->description = description;
}


int House::getCPD() {
    return this->CPD;
}
void House::setCPD(int CPD) {
    this->CPD = CPD;
}

int House::getOccupierID() {
    return this->occupierID;
}
void House::setOccupierID(int occupierID) {
    this->occupierID = occupierID;
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
