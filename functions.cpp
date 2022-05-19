#include <iostream>
using namespace std;
// #include "account.cpp"
// #include "member.cpp"
#include "admin.cpp"
#include <vector>
#include <fstream>
#include <string>
#include <json/value.h>


void getAllData()
{
    Account *acc;
    vector<Account *> memberList;
    string delimiter_char = "-----";
    string data, userName, password, role;
    ifstream myfile("account.dat");
    if (myfile.is_open())
    {
        size_t pos = 0;
        string token;
        while (getline(myfile, data))
        {
            while ((pos = data.find(delimiter_char)) != std::string::npos)
            {
                token = data.substr(0, pos);
                data.erase(0, pos + delimiter_char.length());
                if (userName == "")
                {
                    userName = token;
                }
                else if (password == "")
                {
                    password = token;
                }
            }
            role = data;
            cout << userName << endl;
            cout << password << endl;
            cout << role << endl;
        }
        acc = new Member(userName,password);
        memberList.push_back(acc);

        myfile.close();
    }

    else
        cout << "Unable to open file";
}
