#include "admin.h"
#include "account.cpp"
#include <vector>
#include <string.h>
#include <iostream>

Admin::Admin(){}
vector<string> passwordAdminList;
vector<string> usernameAdminList;

Admin::Admin(int id, string username, string password){
    this->id = id;
    this->account = new Account(username, password);
}

Account Admin::getAccount()
{
    return *account;
}

int Admin::getID(){
    return this->id;
}
void Admin::viewAllMember(vector<Account *> members)
{

}

void Admin::viewAllHouse(vector<House *> houses)
{
    for (House *house : houses) {
        cout << "House ID : " << house->houseID << endl;
        cout << "House Address : " << house->address << endl;
        cout << "House description : " << house->description << endl;
        cout << "OccupantID : " << house->occupantID << endl;
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
