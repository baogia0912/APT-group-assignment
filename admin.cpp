#include <iostream>
using namespace std;
#include "member.h"
#include "admin.h"
#include <vector>
#include "house.h"
#include "account.cpp"

Admin::Admin(){};
Admin::Admin(string username, string password)
{
    this->account = new Account(username, password);
}

Account Admin::getAccount()
{
    return *account;
}

void Admin::viewAllMember(vector<Account *> memberList)
{
    for (int i = 0; i < memberList.size(); i++)
    {
        cout << "Member" + i + 1 << " : " << memberList[i]->username << endl;
    }
}

void Admin::viewAllHouse(vector<House *> houseList)
{
    for (int i = 0; i < houseList.size(); i++)
    {
        cout << "House ID : " << houseList[i]->houseID << endl;
        cout << "House Address : " << houseList[i]->address << endl;
        cout << "House description : " << houseList[i]->description << endl;
        cout << "OccupantID : " << houseList[i]->occupantID << endl;
        for (int j = 0; j < houseList[i]->availablePeriods.size(); j++)
        {
            cout << "P " + j + 1 << ":" << houseList[i]->availablePeriods[j] << endl;
        }
        cout << "Total rating : " << Admin::getHouseRating(houseList[i]->houseRating);
        cout << "Total occupant rating : " << Admin::getOccupantRating(houseList[i]->houseRating);
    }
}

double Admin::getHouseRating(vector<Rating *> houseRating)
{
    double totalRating = 0;
    for (int i = 0; i < houseRating.size(); i++)
    {
        cout << "Comment : " + i + 1 << houseRating[i]->comment << endl;
        totalRating += houseRating[i]->rating;
    }
    return totalRating;
};

double Admin::getOccupantRating(vector<Rating *> occupantRating)
{
    double totalRating = 0;
    for (int i = 0; i < occupantRating.size(); i++)
    {
        cout << "Comment : " + i + 1 << occupantRating[i]->comment << endl;
        totalRating += occupantRating[i]->rating;
    }
    return totalRating;
};

void Admin::getRequest(vector<Request *> requestList){

};

