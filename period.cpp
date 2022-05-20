
#include "period.h"
date::year_month_day
make_year_month_day(int y, int m, int d)
{
    using namespace date;
    return year{y}/m/d;
}
int main () {
    year_month_day end = make_year_month_day(2022, 5, 20);
    year_month_day start = make_year_month_day(2021, 4, 10);
    auto today = floor<days>(system_clock::now());

    cout <<  sys_days{end} - sys_days{start};
    
}