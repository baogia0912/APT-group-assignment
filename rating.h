
#ifndef RATING_H
#define RATING_H

class Rating
{
private:
    string comment;
    double rating;

public:
    Rating();
    Rating(string comment, double rating);
    friend class Admin;
};




#endif