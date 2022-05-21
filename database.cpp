#include "member.cpp"
#include "admin.cpp"
#include <fstream>
#include "json.hpp"
using json = nlohmann::json;

void getAllData(vector<Admin>* adminList, vector<Member>* memberList, vector<House>* houseList) {
    string userName, password;
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
    string userName, password;
    
    json members, admins;
    ofstream member_file("members1.json", ofstream::binary);

    for (int i = 0; i < memberList.size(); i++) {
        cout << memberList[i].getID();
        members[i]["id"] = to_string(memberList[i].getID());
        members[i]["name"] = memberList[i].getAccount().username;
        members[i]["password"] = memberList[i].getAccount().password;
    }
    member_file << members;
}
