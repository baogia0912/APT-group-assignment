#include <iostream>
using namespace std;
class Rating{
    private:
        double rating;
    public:
        Rating(){

        }

        Rating(double rating){
            this->rating = rating;
        }

        void getHouseRating(double rating);
        friend class House;

};