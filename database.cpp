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
        for (auto house : member["house_list"]) {
            tempHouse = new House(house["house_id"], house["address"], house["description"], 
                house["cpd"], house["min_occupier_rating"], house["occupier_id"]);
            tempMember->addHouse(tempHouse);
            for (auto period : house["available_periods"]) 
                tempHouse->getPeriods()->push_back(new Period(period["start_date"], period["end_date"])); 
            for (auto rating : house["ratings"])
                tempHouse->getRatings()->push_back(new Rating(rating["rating"], rating["comment"]));
            for (auto request : house["request_list"])
                tempHouse->getRequests()->push_back(new Request(request["requester_id"], 
                Period(request["period"]["start_date"], request["period"]["end_date"])));
        }
        houseList->push_back(*tempHouse);
        memberList->push_back(*tempMember);
    }
}

void writeAllData(vector<Admin> *adminList, vector<Member> *memberList)
{
    string userName, password;

    json members, admins;
    ofstream member_file("members.json", ofstream::binary);
    ofstream admin_file("admins.json", ofstream::binary);

    for (int i = 0; i < memberList->size(); i++)
    {
        members[i]["id"] = (*memberList)[i].getID();
        members[i]["name"] = (*memberList)[i].getAccount().username;
        members[i]["password"] = (*memberList)[i].getAccount().password;
        for (int j = 0; j < ((*memberList)[i].getAllHouses()).size(); j++)
        {
            members[i]["house_list"][j]["house_id"] = (*memberList)[i].getAllHouses()[j]->getHouseID();
            members[i]["house_list"][j]["address"] = (*memberList)[i].getAllHouses()[j]->getAddress();
            members[i]["house_list"][j]["description"] = (*memberList)[i].getAllHouses()[j]->getDescription();
            members[i]["house_list"][j]["cpd"] = (*memberList)[i].getAllHouses()[j]->getCPD();
            members[i]["house_list"][j]["occupier_id"] = (*memberList)[i].getAllHouses()[j]->getOccupierID();
            members[i]["house_list"][j]["min_occupier_rating"] = (*memberList)[i].getAllHouses()[j]->getMinOccupierRating();
            for (int k = 0 ; k < ((*memberList)[i].getAllHouses()[j]->getRequests())->size(); k ++) 
            {
                members[i]["house_list"][j]["request_list"][k]["requester_id"] = (*(*memberList)[i].getAllHouses()[j]->getRequests())[k]->getRequesterID();            
                members[i]["house_list"][j]["request_list"][k]["period"]["start_date"] = (*(*memberList)[i].getAllHouses()[j]->getRequests())[k]->getPeriod().getStartDate();            
                members[i]["house_list"][j]["request_list"][k]["period"]["end_date"] = (*(*memberList)[i].getAllHouses()[j]->getRequests())[k]->getPeriod().getEndDate();            
            }
            for (int k = 0 ; k < ((*memberList)[i].getAllHouses()[j]->getRatings())->size(); k ++) 
            {
                members[i]["house_list"][j]["ratings"][k]["rating"] = (*(*memberList)[i].getAllHouses()[j]->getRatings())[k]->getRating();            
                members[i]["house_list"][j]["ratings"][k]["comment"] = (*(*memberList)[i].getAllHouses()[j]->getRatings())[k]->getComment();            
            }
            for (int k = 0 ; k < ((*memberList)[i].getAllHouses()[j]->getPeriods())->size(); k ++) 
            {
                members[i]["house_list"][j]["available_periods"][k]["start_date"] = (*(*memberList)[i].getAllHouses()[j]->getPeriods())[k]->getStartDate();            
                members[i]["house_list"][j]["available_periods"][k]["end_date"] = (*(*memberList)[i].getAllHouses()[j]->getPeriods())[k]->getEndDate();            
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
