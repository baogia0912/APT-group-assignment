#ifndef PERIOD_H
#define PERIOD_H
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <sstream>
#include "time.h"
using namespace date;
using namespace std::chrono;

class Period
{
private:
    double startDate;
    double endDate;

public:
    Period();
    Period(double startDate, double endDate);
};
#endif