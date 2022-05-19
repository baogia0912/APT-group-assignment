#include <iostream>
#include <vector>
using namespace std;

class House;

class Member{
    private:
        double rating;
    public:
        Member(){

        }

        Member(double rating){
            this->rating = rating;
        }

        void getHouseRating(double rating);
        friend class House;

};


class House {
    private:
        string houseID;
        string occupierID;
        string location;
        string description;
        vector<double>houseRating;
        vector<double>occupierRating;
    public:
        House(){

        }

        House(string ID, string location, string description, vector<double>houseRating, vector<double>occupierRating){
            this->ID = ID;
            this->location = location;
            this->description = description;
            this->houseRating = houseRating;
            this->occupierRating = occupierRating;
        }

        friend void Member::getHouseRating(double rating){
            houseRating.pushback(rating);
        }
        
};