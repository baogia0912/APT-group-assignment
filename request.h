#ifndef REQUEST_H
#define REQUEST_H
#include "period.h"

class Request
{
private:
    Period period;
    string requesterID;

public:
    Request();
    Request(Period period, string requesterID);
};

#endif