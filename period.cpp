#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <sstream>
class Period{
    private:
        int d, m, y;
        const int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    public:
        Period(){

        }
        
        Period(int d, int m, int y){
            this->d = d;
            this->m = m;
            this->y = y;
        }

        int countLeapYears (Period p){
            int years = p.y;

            if(p.m <= 2){
                years--;
            }
            return (years/4) - (years/100) + (years/400);
        }

        int getDays(Period p1, Period p2){
            long int n1 = p1.y * 365 + p1.d;
            for(int i = 0; i < p1.m - 1, i++){
                n1 += monthDays[i];
            }
            n1 += countLeapYears(p1);
            
            long int n2 = p2.y * 365 + p2.d;
            for(int i = 0; i < p2.m - 1; i++){
                n2 += monthDays[i];
            }
            n2 += countLeapYears(p2);

            return (n2 - n1);
        }

        /*string setDate(string start, string end){
            startDate = start;
            endDate = end;
            return startDate;
            return endDate;
        }
        
        void getDays(string startDate, string endDate){
            string startDay = startDate.substr(0, 2);
            string endDay = endDate.substr(0, 2);
            string startMonth = startDate.substr(3, 2);
            string endMonth = endDate.substr(3, 2);
            string startYear = startDate.substr(6, 4);
            string endYear = endDate.substr(6, 4);
            int days = (stoi(endDay) - stoi(startDay)) + (stoi(endMonth) - stoi(startMonth));
        }*/
};

int main (){
    int startDay;
    int startMonth;
    int startYear;
    int endDay;
    int endMonth;
    int endYear;
    cout << "Enter start day:" << endl;
    cin >> startDay;
    cout << "Enter start month:" << endl;
    cin >> startMonth;
    cout << "Enter start year:" << endl;
    cin >> startYear;
    cout << "Enter end day:" << endl;
    cin >> endDay;
    cout << "Enter end month:" << endl;
    cin >> endMonth;
    cout << "Enter end year:" << endl;
    cin >> endYear;
    cout << "Start date: " << startDay << "/" << startMonth << "/" << startYear << endl;
    cout << "End date: " << endDay << "/" << endMonth << "/" << endYear << endl;
    
    
    Period start = {startDay, startMonth, startYear};
    Period end = {endDay , endMonth, endYear};
   cout << "Days: " << int Period::getDays(start, end);
}
