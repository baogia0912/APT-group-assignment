#include <iostream>
using namespace std;

//Menu for guest;
/* 
Option 1: Guest require to be a member;

Option 2: Guest continue viewing house design. 
*/

void menuForGuest(){
    int option;
    cout<<"Please choose the following suitable option for you:"<<endl;
    cout<<"Enter 1 to register a member account.\n"
        <<"Enter 2 to view all house details.\n"
        <<"In case you would like to access the reviews section and avaiability. Member registration is compulsory"<<endl;
    cin>>option;

switch (option)
{
case 1:
    registerMember();
    break;
case 2:
    viewAllHouses();
    break;
default:
    break;
}
}