#ifndef RATING_CPP
#define RATING_CPP
/* code */

#include "rating.h"

Rating::Rating(){};
Rating::Rating(double rating, string comment)
{
    this->comment = comment;
    this->rating = rating;
}

double Rating::getRating() {
    return this->rating;
}
void Rating::setRating(double rating) {
    this->rating = rating;
}

string Rating::getComment() {
    return this->comment;
}
void Rating::setComment(string comment) {
    this->comment = comment;
}
#endif //RATING_CPP
