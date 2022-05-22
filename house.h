#ifndef HOUSE_H
#define HOUSE_H
#include "rating.cpp"
#include "period.cpp"
#include "request.cpp"

class House{
private:
    vector<Period *> availablePeriods;
    vector<Rating *> ratings;
    vector<Request *> requests;
    double minOccupierRating;
    string address;
    int houseID;
    string description;
    int CPD;
    int occupierID;

public:
    
    House();
    House(int houseID, string address, string description, int CPD);
    House(int houseID, string address, string description, int CPD, double minOccupierRating, int occupierID);

    double getMinOccupierRating();
    void setMinOccupierRating(double minOccupierRating);
    string getAddress();
    void setAddress(string address);
    int getHouseID();
    void setHouseID(int houseID);
    string getDescription();
    void setDescription(string description);
    int getCPD();
    void setCPD(int CPD);
    int getOccupierID();
    void setOccupierID(int occupierID);

    vector<Period *> *getPeriods();
    void setPeriods(vector<Period *> periods);
    vector<Rating *> *getRatings();
    void setRatings(vector<Rating *> ratings);
    vector<Request *> *getRequests();
    void setRatings(vector<Request *> requests);

    friend ostream &operator<<(ostream &os, const House &dt);
    double getHouseAvgRating();
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