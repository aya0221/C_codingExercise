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

    cout.setf(ios::left);
            cout<<setw(10);
    cout<<"*" <<123 <<"*"<<endl;


    cout<<"*";

    cout.setf(ios::right);
                cout<<setw(10);
    cout<<"*" <<123 <<"*"<<endl;

    return 0;
}