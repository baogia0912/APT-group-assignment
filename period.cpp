
#include "period.h"
// // class Period{
// //     private:
// //         string startDate;
// //         string endDate;
// //     public:
// //         Period(){

// //         }
        
// //         Period(string startDate, string endDate){
// //             this->startDate = startDate;
// //             this->endDate = endDate;
// //         }

// //         string setDate(string start, string end){
// //             startDate = start;
// //             endDate = end;
// //             return startDate;
// //             return endDate;
// //         }
// //         /*dd/mm/yyyy*/
// //         void getDays(string startDate, string endDate){
// //             string startDay = startDate.substr(0, 2);
// //             string endDay = endDate.substr(0, 2);
// //             string startMonth = startDate.substr(3, 2);
// //             string endMonth = endDate.substr(3, 2);
// //             string startYear = startDate.substr(6, 4);
// //             string endYear = endDate.substr(6, 4);
// //             int days = (stoi(endDay) - stoi(startDay)) + (stoi(endMonth) - stoi(startMonth));
// //         }
// // };

// int main (){
//     int startDay;
//     int startMonth;
//     int startYear;
//     int endDay;
//     int endMonth;
//     int endYear;
//     cout << "Enter start day:" << endl;
//     cin >> startDay;
//     cout << "Enter start month:" << endl;
//     cin >> startMonth;
//     cout << "Enter start year:" << endl;
//     cin >> startYear;
//     cout << "Enter end day:" << endl;
//     cin >> endDay;
//     cout << "Enter end month:" << endl;
//     cin >> endMonth;
//     cout << "Enter end year:" << endl;
//     cin >> endYear;
//     cout << "Start date: " << startDay << "/" << startMonth << "/" << startYear << endl;
//     cout << "End date: " << endDay << "/" << endMonth << "/" << endYear << endl;
    
    
//     Period start = {startDay, startMonth, startYear};
//     Period end = {endDay , endMonth, endYear};
   
// }

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