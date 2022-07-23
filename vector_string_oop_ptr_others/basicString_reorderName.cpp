/*
input:  First_Name Middle_Initial, Last_Name
output: Last_Name, First_Name Middle_Initial
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName, middleName, lastName;

    cout<<"Please enter your name: ";
    cin>>firstName>>middleName>>lastName;   //input order: First_Name Middle_Initial, Last_Name
    cout<<lastName<<", "<<firstName<<" "<< middleName[0]<<".\n";    //outputprder: Last_Name, First_Name Middle_Initial

    return 0;
}
