#ifndef REQUEST_CPP
#define REQUEST_CPP
/* code */

#include "request.h"

Request::Request()
{
}
Request::Request(int requesterID, Period period)
{
    this->period = period;
    this->requesterID = requesterID;
}
Period Request::getPeriod() {
    return this->period;
}
void Request::setPeriod(Period period) {
    this->period = period;
}


int Request::getRequesterID() {
    return this->requesterID;
}
void Request::setRequesterID(int requesterID) {
    this->requesterID = requesterID;
}
#endif //REQUEST_CPP
