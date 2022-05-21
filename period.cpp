
#include "period.h"

/*default constructor*/
Period::Period()
{
}

/*constructor*/
Period::Period(year_month_day startDate, year_month_day endDate)
{
    this->startDate = startDate;
    this->endDate = endDate;
}

/*function to set the start date*/
void Period::setStartDate(year_month_day start)
{
    this->startDate = start;
}

/*function to set the end date*/
void Period::setEndDate(year_month_day end)
{
    this->endDate = end;
}

/*function to get the start date*/ 
year_month_day Period::getStartDate()
{
    return this->startDate;
}

/*function to get the end date*/ 
year_month_day Period::getEndDate()
{
    return this->endDate;
}

/* function to calculate the difference between 2 dates*/
std::chrono::duration<int, std::ratio<86400, 1>> Period::getGap()
{
    return sys_days{this->endDate} - sys_days{this->startDate};
}

/* function to format date*/
date::year_month_day
make_year_month_day(int y, int m, int d)
{
    using namespace date;
    return year{y}/m/d;
}

/* function to set the period*/
void Period::setPeriod()
{   
    /*use try-catch to handle exception*/
    try
    {
        Period p1;
        int startDay;
        int startMonth;
        int startYear;
        int endDay;
        int endMonth;
        int endYear;
        
        /*user input for start date*/
        cout << "Enter start day:" << endl;
        cin >> startDay;
        cout << "Enter start month:" << endl;
        cin >> startMonth;
        cout << "Enter start year:" << endl;
        cin >> startYear;
        
        /*for months that have 31 days*/
        if (startMonth == 1 || startMonth == 3 || startMonth == 5 || startMonth == 7 || startMonth == 8 || startMonth == 10 || startMonth == 12)
        {
            if (startDay <= 31)
            {
                year_month_day start = make_year_month_day(startYear, startMonth, startDay);
                p1.setStartDate(start);
            }
            else
            {
                throw(startMonth);
            }
        }

        /*for months that have 30 days*/
        if (startMonth == 4 || startMonth == 6 || startMonth == 9 || startMonth == 11)
        {
            if (startDay <= 30)
            {
                year_month_day start = make_year_month_day(startYear, startMonth, startDay);
                p1.setStartDate(start);
            }
            else
            {
                throw(startMonth);
            }
        }
        
        /*only for february*/
        if (startMonth == 2)
        {
            if (startDay <= 29)
            {
                year_month_day start = make_year_month_day(startYear, startMonth, startDay);
                p1.setStartDate(start);
            }
            else
            {
                throw(startMonth);
            }
        }

        /*user input for end date*/
        cout << "Enter end day:" << endl;
        cin >> endDay;
        cout << "Enter end month:" << endl;
        cin >> endMonth;
        cout << "Enter end year:" << endl;
        cin >> endYear;

        /*for months that have 31 days*/
        if (endMonth == 1 || endMonth == 3 || endMonth == 5 || endMonth == 7 || endMonth == 8 || endMonth == 10 || endMonth == 12)
        {
            if (endDay <= 31)
            {
                year_month_day end = make_year_month_day(endYear, endMonth, endDay);
                p1.setEndDate(end);
            }
            else
            {
                throw(endMonth);
            }
        }

        /*for months that have 30 days*/
        if (endMonth == 4 || endMonth == 6 || endMonth == 9 || endMonth == 11)
        {
            if (endDay <= 30)
            {
                year_month_day end = make_year_month_day(endYear, endMonth, endDay);
                p1.setEndDate(end);
            }
            else
            {
                throw(endMonth);
            }
        }

        /*only for february*/
        if (endMonth == 2)
        {
            if (endDay <= 29)
            {
                year_month_day end = make_year_month_day(endYear, endMonth, endDay);
                p1.setEndDate(end);
            }
            else
            {
                throw(endMonth);
            }
        }

        // auto today = floor<days>(system_clock::now());
    
        cout << "Requested period: " << p1.getStartDate() << " to "
             << p1.getEndDate() << "\n"; //print out the period from date to date
        cout << "Total requested days: " << p1.getGap() << "\n"; //print out the total days of the period
    }
    /*catch error and handle it*/
    catch (int x)
    {
        cout << "Please enter the month that have the correct numbers of day!" << endl;
        cin.clear();
    }
}
