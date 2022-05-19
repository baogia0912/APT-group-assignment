#include <iostream>
using namespace std;
// #include "account.cpp"
// #include "member.cpp"
// #include "admin.cpp"
#include <vector>
#include <fstream>
#include <string>
#include "json.hpp"
using json = nlohmann::json;

void getAllData() {
    // Account *acc;
    // vector<Account *> memberList;
    // vector<Account *> adminList;
    string data, userName, password, role;

    json member;
    ifstream member_file("members.json", ifstream::binary);
    member_file >> member;

    cout << member;


}

int main()
{   
    getAllData();
    // acc = new Member ("dwddw","dwdwdw");        
}
