#ifndef REQUEST_H
#define REQUEST_H
#include "period.h"

class Request
{
private:
    Period period;
    int requesterID;

public:
    Request();
    Request(int requesterID, Period period);

    Period getPeriod();
    void setPeriod(Period period);
    int getRequesterID();
    void setRequesterID(int requesterID);
    friend ostream &operator<<(ostream &os, const Request &request);
};

ostream &operator<<(ostream &os, const Request &request)
{
    os << "Request ID : " << request.requesterID << endl
       << "Period : " << request.period << endl;
    ;
    return os;
};

#endif