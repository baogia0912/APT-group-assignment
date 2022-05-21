#include "request.h"

Request::Request()
{
}
Request::Request(Period period, int requesterID)
{
    this->period = period;
    this->requesterID = requesterID;
}
