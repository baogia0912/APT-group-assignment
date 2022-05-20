#ifndef RATING_H
#define RATING_H
using namespace std;
#include <iostream>

class Rating
{
private:
    string comment;
    double rating;

public:
    Rating();
    Rating(string comment, double rating);
};
#endif