#include <iostream>
#include <vector>
using namespace std;

class House {
    private:
        vector<Rating*> houseRating;
    public:
        string location;
        string description;
        float scoreRating[];

        House(){

        }

        House(string location, string description, float scoreRating[]){
            this->location = location;
            this->description = description;
            for(int i = 0; i < sizeof(scoreRating); i++){
                this->scoreRating[i] = scoreRating[i];
            }
        }
        
        void houseRatingScore (float scoreRating[]){
            float sum = 0.0;
            for(int i = 0; i < sizeof(scoreRating); i++){
                sum += scoreRating[i];
            }
        }
    friend class Member;
};