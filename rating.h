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
    Rating(string comment, double rating);
    friend class Admin;
    friend class Member;
};





#endif