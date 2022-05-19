#include "period.h"
#ifndef REQUEST_H
#define REQUEST_H

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