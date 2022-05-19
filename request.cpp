#include <iostream>
using namespace std;
#include "request.h"
#include "period.h"

Request::Request()
{
}
Request::Request(Period period, string requesterID)
{
    this->period = period;
    this->requesterID = requesterID;
}