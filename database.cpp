#include "member.cpp"
#include "admin.cpp"
#include "house.cpp"
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

void getAllData(vector<Admin> *adminList, vector<Member> *memberList, vector<House> *houseList)
{   Member * tempMember;
    House * tempHouse;
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
        tempMember = new Member(member["id"], member["name"], member["password"]);
        tempHouse = new House(member["house_list"]["house_id"], member["house_list"]["address"], member["house_list"]["description"], 
            member["house_list"]["cpd"], member["house_list"]["min_occupier_rating"], member["house_list"]["occupier_id"]);
        tempMember->addHouse(tempHouse);
            tempHouse->getPeriods().push_back(new Period(member["house_list"]["available_periods"]["start_date"], member["house_list"]["available_periods"]["end_date"])); 
            tempHouse->getRatings().push_back(new Rating(member["house_list"]["rating"]["rating"], member["house_list"]["rating"]["comment"]));
            tempHouse->getRequests().push_back(new Request(member["house_list"]["request_list"]["requester_id"], 
            Period(member["house_list"]["request_list"]["period"]["start_date"], member["house_list"]["request_list"]["period"]["end_date"])));
    }
}

void writeAllData(vector<Admin> *adminList, vector<Member> *memberList)
{
    string userName, password;

    json members, admins;
    ofstream member_file("members1.json", ofstream::binary);
    ofstream admin_file("admin1.json", ofstream::binary);

    for (int i = 0; i < memberList->size(); i++)
    {
        members[i]["id"] = (*memberList)[i].getID();
        members[i]["name"] = (*memberList)[i].getAccount().username;
        members[i]["password"] = (*memberList)[i].getAccount().password;
        for (int j = 0; j < ((*memberList)[i].getAllHouses()).size(); j++)
        {
            members[i]["house_list"][j]["house_id"] = (*memberList)[i].getAllHouses()[j]->houseID;
            members[i]["house_list"][j]["address"] = (*memberList)[i].getAllHouses()[j]->address;
            members[i]["house_list"][j]["description"] = (*memberList)[i].getAllHouses()[j]->description;
            members[i]["house_list"][j]["cpd"] = (*memberList)[i].getAllHouses()[j]->CPD;
            members[i]["house_list"][j]["occupier_id"] = (*memberList)[i].getAllHouses()[j]->occupierID;
            members[i]["house_list"][j]["min_occupier_rating"] = (*memberList)[i].getAllHouses()[j]->minOccupierRating;
            for (int k = 0 ; k < (*memberList)[i].getAllHouses()[j]->getRequests().size(); k ++) 
            {
                members[i]["house_list"][j]["request_list"][k]["requester_id"] = (*memberList)[i].getAllHouses()[j]->getRequests()[k]->getRequesterID();            
                members[i]["house_list"][j]["request_list"][k]["period"]["start_date"] = (*memberList)[i].getAllHouses()[j]->getRequests()[k]->getPeriod().getStartDate();            
                members[i]["house_list"][j]["request_list"][k]["period"]["end_date"] = (*memberList)[i].getAllHouses()[j]->getRequests()[k]->getPeriod().getEndDate();            
            }
            for (int k = 0 ; k < (*memberList)[i].getAllHouses()[j]->getRatings().size(); k ++) 
            {
                members[i]["house_list"][j]["rating"][k]["rating"] = (*memberList)[i].getAllHouses()[j]->getRatings()[k]->getRating();            
                members[i]["house_list"][j]["rating"][k]["comment"] = (*memberList)[i].getAllHouses()[j]->getRatings()[k]->getComment();            
            }
            for (int k = 0 ; k < (*memberList)[i].getAllHouses()[j]->getPeriods().size(); k ++) 
            {
                members[i]["house_list"][j]["available_periods"][k]["start_date"] = (*memberList)[i].getAllHouses()[j]->getPeriods()[k]->getStartDate();            
                members[i]["house_list"][j]["available_periods"][k]["end_date"] = (*memberList)[i].getAllHouses()[j]->getPeriods()[k]->getEndDate();            
            }
        }
    }

    for (int i = 0; i < adminList->size(); i++)
    {
        admins[i]["id"] = (*adminList)[i].getID();
        admins[i]["name"] = (*adminList)[i].getAccount().username;
        admins[i]["password"] = (*adminList)[i].getAccount().password;
    }
    member_file << members;
    admin_file << admins;
}
