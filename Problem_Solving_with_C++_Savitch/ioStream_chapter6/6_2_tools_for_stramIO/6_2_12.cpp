/*
the following two print the same things

cout.width(5)
setw(5);

*/

#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){

    cout<<"*";
    cout.width(20);
    cout<<123
        <<"*" <<123 <<"*"<<endl;


    cout<<"*"<< setw(20) <<123 <<"*"<<endl;
    return 0;
}