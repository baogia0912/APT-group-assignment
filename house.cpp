#include <iostream>
#include <vector>
using namespace std;

class House {
    private:
        string houseID;
        string adress;
        string description;
        vector<double>availablePeriods;
        vector<double>houseRating;
        
    public:
        string occupierID;
        double minOccupierRating;
        House(){

        }

        House(string ID, string location, string description, vector<double>houseRating, vector<double>occupierRating){
            this->houseID = houseID;
            this->adress = adress;
            this->description = description;
            this->houseRating = houseRating;
            this->minOccupierRating = minOccupierRating;
        }

        friend void Rating::getHouseRating(double rating){
            houseRating.pushback(rating);
        }
        
};