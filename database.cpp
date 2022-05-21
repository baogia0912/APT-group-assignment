#include "member.cpp"
#include "admin.cpp"
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

void getAllData(vector<Admin> *adminList, vector<Member> *memberList, vector<House> *houseList)
{
    string userName, password;
    json members, admins;
    ifstream member_file("members.json", ifstream::binary);
    ifstream admin_file("admins.json", ifstream::binary);
    member_file >> members;
    admin_file >> admins;
    for (auto admin : admins)
    {
        adminList->push_back(Admin(admin["id"], admin["name"], admin["password"]));
    }

    for (auto member : members)
    {
        memberList->push_back(Member(member["id"], member["name"], member["password"]));
        houseList->push_back(House(member['houseList']["house_id"], member['houseList']["address"],
                                   member['houseList']["description"], member['houseList']["cpd"]));
    }
}

void writeAllData(vector<Admin> *adminList, vector<Member> *memberList)
{
    string userName, password;

    json members, admins;
    ofstream member_file("members1.json", ofstream::binary);
    ofstream member_file("admin1.json", ofstream::binary);

    for (int i = 0; i < memberList->size(); i++)
    {
        members[i]["id"] = to_string((*memberList)[i].getID());
        members[i]["name"] = (*memberList)[i].getAccount().username;
        members[i]["password"] = (*memberList)[i].getAccount().password;
        for (int j = 0; j < ((*memberList)[i].getAllHouses()).size(); j++)
        {
            members[i]["house_list"]["house_id"] = (*memberList)[i].getAllHouses()[j]->houseID;
            members[i]["house_list"]["address"] = (*memberList)[i].getAllHouses()[j]->address;
            members[i]["house_list"]["description"] = (*memberList)[i].getAllHouses()[j]->description;
            members[i]["house_list"]["cpd"] = (*memberList)[i].getAllHouses()[j]->CPD;
            members[i]["house_list"]["occupier_id"] = (*memberList)[i].getAllHouses()[j]->occupierID;
            members[i]["house_list"]["min_occupier_rating"] = (*memberList)[i].getAllHouses()[j]->minOccupierRating;
            for (int k  =0 ; k <(*memberList)[i].getAllHouses()[j]->requests.size()  ; k ++ ) {
            // members[i]["house_list"]["request"][""] = (*memberList)[i].getAllHouses()[j]->requests[k];            

            }
        }
        members[i]["house_list"]["house_id"] = (*memberList)[i].getID();
        members[i]["house_list"]["house_id"] = (*memberList)[i].getID();
    }

    for (int i = 0; i < adminList->size(); i++)
    {
        admins[i]["id"] = to_string((*adminList)[i].getID());
        admins[i]["name"] = (*adminList)[i].getAccount().username;
        admins[i]["password"] = (*adminList)[i].getAccount().password;
    }
    member_file << members;
}
