#include "admin.h"
#include "account.cpp"

Admin::Admin() {}
vector<string> passwordAdminList;
vector<string> usernameAdminList;

Admin::Admin(int id, string username, string password)
{
    this->id = id;
    this->account = Account(username, password);
}

Account Admin::getAccount()
{
    return this->account;
}

int Admin::getID()
{
    return this->id;
}
void Admin::viewAllMember(vector<Account *> members)

{
    for (Account *mem : members)
    {
        cout << mem->username;
    }
}

void Admin::viewAllHouse(vector<House *> houses)
{
    for (House *house : houses)
    {
        cout << "House ID : " << house->houseID << endl;
        cout << "House Address : " << house->address << endl;
        cout << "House description : " << house->description << endl;
        cout << "OccupantID : " << house->occupierID << endl;
        for (int j = 0; j < houses[j]->availablePeriods.size(); j++)
        {
            cout << "P " + j + 1 << ":" << houses[j]->availablePeriods[j] << endl;
        }
        cout << "Total rating : " << Admin::getHouseRating(house->houseRating);
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

void Admin::viewAllRequest(vector<Request *> requestList){

};
