#include <iostream>
using namespace std;
#include "account.cpp"
// #include "member.cpp"
// #include "admin.cpp"
#include <vector>
#include <fstream>
#include <string>

void checkAccount()

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

        myfile.close();
    }

    else
        cout << "Unable to open file";
}

int main()
{   
    Account * acc;
    acc = new  ;
        
    // checkAccount();
}