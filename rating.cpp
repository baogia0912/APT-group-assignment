#include "rating.h"

Rating::Rating(){};
Rating::Rating(string comment, double rating)
{
    this->comment = comment;
    this->rating = rating;
}
