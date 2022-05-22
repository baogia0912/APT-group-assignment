#ifndef GUEST_H
#define GUEST_H
#include "member.cpp"
#include "house.h"
#include <iostream>
using namespace std;
class Guest
{

public:
    Guest();

    Member* signUp(vector<Member>* members);

    void viewHouseDetails(vector<House> houseList);
};

#endif
