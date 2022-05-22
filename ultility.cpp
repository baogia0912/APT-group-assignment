#include <iostream>
#include <vector>
#include "member.h"
#include "house.h"
using namespace std;
//function to calculate nex ID for member 
int nextID(vector<Member> members) {
    int highestID = 0;
    for (Member mem : members)
    {
        if (mem.getID() > highestID)
            highestID = mem.getID();
    }
    return ++highestID;
}


//function to calculate next ID for houses
int nextID(vector<House> *houses) {
    int highestID = 0;
    for (House house : *houses)
    {
        if (house.getHouseID() > highestID)
            highestID = house.getHouseID();
    }
    return ++highestID;
}