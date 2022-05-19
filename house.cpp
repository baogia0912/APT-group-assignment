#include <iostream>
#include <vector>
using namespace std;

class House {
    private:
        string adress;    
        string houseID;
    public:
        string location;
        string description;
        vector<double>availablePeriods;
        vector<Rating*> houseRating;
        string occupierID;
        double minOccupierRating;
        House(){

        }

        House(string ID, string location, string description, vector<Rating*>houseRating, vector<double>occupierRating){
            this->houseID = houseID;
            this->adress = adress;
            this->description = description;
            this->houseRating = houseRating;
            this->minOccupierRating = minOccupierRating;
        }

        void getHouseRating(Rating &rating){
        }
    friend class Member;
};