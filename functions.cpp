#include <iostream>
using namespace std;
// #include "account.cpp"
#include "member.cpp"
#include "admin.cpp"
#include <vector>
#include <fstream>
#include <string>
#include "json.hpp"
using json = nlohmann::json;

void getAllData(vector<Admin*> adminList, admin_file >> admins) {
    // Account *acc;
    // vector<Account *> memberList;
    // vector<Account *> adminList;
    string data, userName, password, role;
    vector<Admin*> adminList;
    vector<Member*> memberList;
    
    json members, admins;
    ifstream member_file("members.json", ifstream::binary);
    ifstream admin_file("admins.json", ifstream::binary);
    member_file >> members;
    admin_file >> admins;

    for (auto admin: admins) {
        adminList.push_back(new Admin());
        cout << admin << endl;
    }

    for (auto member: members) {
        // cout << member["id"];
    }


}

int main()
{   
    getAllData();
    // acc = new Member ("dwddw","dwdwdw");        
}
