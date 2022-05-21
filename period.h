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

class Period{


private:
    year_month_day startDate;
    year_month_day endDate;
public:
    Period();
    Period(year_month_day startDate, year_month_day endDate);
    void setStartDate(year_month_day start);
    void setEndDate(year_month_day end);
    year_month_day getStartDate();
    year_month_day getEndDate();
    std::chrono::duration<int, std::ratio<86400, 1>> getGap();
    void setPeriod();
};
#endif