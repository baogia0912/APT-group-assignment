#include <iostream>
#include <vector>
#include "member.h"
using namespace std;

int nextID(vector<Member> members) {
    int highestID = 0;
    for (Member mem : members)
    {
        if (mem.getID() > highestID)
            highestID = mem.getID();
    }
    return ++highestID;
}