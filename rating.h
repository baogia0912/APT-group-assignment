#ifndef RATING_H
#define RATING_H
#include <iostream>
using namespace std;

class Rating
{
private:
    string comment;
    double rating;

public:
    Rating();
    Rating(double rating, string comment);

    double getRating();
    void setRating(double rating);
    string getComment();
    void setComment(string comment);
};
#endif