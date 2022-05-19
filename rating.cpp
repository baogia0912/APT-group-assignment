#include <iostream>
using namespace std;

class Rating {
    private:
        string comment;
        double rating;

    public: 
        Rating (){};
        Rating (string comment , double rating) {
            this->comment = comment;
            this->rating = rating;
        }
};


