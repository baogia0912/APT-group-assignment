#include <iostream>
using namespace std;
class Period{
    private:
        double startDate;
        double endDate;
    public:
        Period(){

        }

        Period(double startDate, double endDate){
            this->startDate = startDate;
            this->endDate = endDate;
        }
};
