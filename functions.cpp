#include "member.cpp"
#include "admin.cpp"
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;
#include "account.h"

void getAllData(vector<Admin>* adminList, vector<Member>* memberList) {
    // Account *acc;
    // vector<Account *> memberList;
    // vector<Account *> adminList;
    string data, userName, password, role;
    
    json members, admins;
    ifstream member_file("members.json", ifstream::binary);
    ifstream admin_file("admins.json", ifstream::binary);
    member_file >> members;
    admin_file >> admins;

    for (auto admin: admins) {
        adminList->push_back(Admin(admin["id"], admin["name"], admin["password"]));
    }

    for (auto member: members) {
        memberList->push_back(Member(member["id"], member["name"], member["password"]));
    }
}

void writeAllData(vector<Admin> adminList, vector<Member> memberList) {
    // Account *acc;
    // vector<Account *> memberList;
    // vector<Account *> adminList;
    string data, userName, password, role;
    
    json members, admins;
    ofstream member_file("members1.json", ofstream::binary);
    // ifstream admin_file("admins.json", ifstream::binary);
    // admin_file >> admins;

    // for (auto admin: admins) {
        // adminList->push_back(Admin(admin["id"], admin["name"], admin["password"]));
    // }
    for (int i = 0; i < memberList.size(); i++) {
        members[i]["id"] = memberList[i].getID();
        members[i]["name"] = memberList[i].getAccount().username;
        members[i]["password"] = memberList[i].getAccount().password;
    }
    member_file << members;
}

int main()
{   
    vector<Admin> adminList;
    vector<Member> memberList;
    getAllData(&adminList, &memberList);

    writeAllData(adminList, memberList);
}
