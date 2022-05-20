#include <vector>
#include "member.h"
#include "house.h"
#ifndef GUEST_H
#define GUEST_H

class Guest
{

public:
    Guest();

    Member* signUp(vector<Member*> members);

    void viewLimitedHouse(vector<House> houseList);
};

#endif
