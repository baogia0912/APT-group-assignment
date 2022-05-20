#include "request.h"

Request::Request()
{
}
Request::Request(Period period, string requesterID)
{
    this->period = period;
    this->requesterID = requesterID;
}