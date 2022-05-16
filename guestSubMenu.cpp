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
    cin>>option;
    cout<<"Enter 1 to register a member account.\n"
        <<"Enter 2 to continue view the view all house details.\n"
        <<"In case you would like to access the reviews section and avaiability. Member registration is compulsory"<<endl;
switch (option)
{
case 1:
    // Code for member.
    break;
case 2:
    cout<<"Have a good time to explore us"<<endl;
    break;
default:
    break;
}
}