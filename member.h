#ifndef MEMBER_H
#define MEMBER_H
#include "account.h"
#include "house.h"



/*
5. A member can list his/her house available to be occupied (with consuming points, and 
minimum required occupier rating), and unlist it if wanted. 
6. A member can search for all available suitable houses for a particular city (suitable 
with his current credit points and rating score). 
7. A member can request to occupy a house. 
8. A member can view all requests to his listed house. 
9. A member can accept a request (reject all other requests). 
10. A member can occupy the successfully requested house. 
11. A member can rate each of his/her occupied houses (score and comment). 
12. A member can rate each of the occupiers who had used his/her house (score and 
comment). 
 */


class Member
{

private:
    int id;
    Account *acc;
    vector<House *> houses;
    vector<Request> requests;
    vector<Rating *> ratings;
    int credits;

public:
    Member();
    Member(string username, string password);
    Member(int id, string username, string password);
    Account getAccount();
    int getID();
    
    void createRating(House *house);
};

#endif
