#include "admin.h"
#include "account.cpp"

Admin::Admin() {}

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

void Admin::viewAllMember(vector<Member> *members)
{
    for (Member mem : *members)
    {
        cout << "ID : " << mem.getID() << endl;
        cout << "Username : " << mem.getAccount().getUsername() << endl;
        cout << "Password : " << mem.getAccount().getPassword() << endl;
        cout << "Creadits : " << mem.getCreadit() << endl;
        cout << "Self Rating : " << mem.getAverageSelfRating(mem.getRatings()) << endl;
        for (House *house : mem.getAllHouses())
        {
            cout << "House ID " << house->getHouseID() << endl;
            cout << "House address " << house->getAddress() << endl;
            cout << endl;
        }
    }
}

void Admin::viewAllHouse(vector<House> *houseList)
{
    Member *mem;
    for (House house : *houseList)
    {
        cout << house << endl;
        for (Request *request : *house.getRequests())
        {
            cout << "Requester ID : " << request->getRequesterID() << endl;
            cout << "Period : "
                 << "from " << request->getPeriod().getStartDate() << endl
                 << " to " << request->getPeriod().getEndDate() << endl;
        }
        cout << endl;
        for (Rating *rating : *house.getRatings())
        {
            cout << "Rating : " << rating->getComment() << endl;
            cout << "Comment : " << rating->getRating() << endl;
        }
        cout << endl;
        for (Period *period : *house.getPeriods())
        {
            cout << "From " << period->getStartDate() << " to "
                 << period->getEndDate() << endl;
        }

        cout << endl;
    }
}
