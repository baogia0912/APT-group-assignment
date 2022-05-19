#include <iostream>
#include "rating.h"
using namespace std;

Rating::Rating(){};
Rating::Rating(string comment, double rating)
{
    this->comment = comment;
    this->rating = rating;
}
