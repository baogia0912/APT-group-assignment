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
    Request(Period period,int requesterID);
};

#endif