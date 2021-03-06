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
    year_month_day startDate;
    year_month_day endDate;

public:
    Period();
    Period(string startDate, string endDate);
    void setStartDate(string start);
    void setEndDate(string end);
    string getStartDate();
    string getEndDate();
    std::chrono::duration<int, std::ratio<86400, 1>> getGap();
    void setPeriod();
    friend ostream &operator<<(ostream &os, const Period &period);
};

ostream &operator<<(ostream &os, const Period &period)
{
    os << "From " << period.startDate << " to " << period.endDate;
    return os;
};
#endif