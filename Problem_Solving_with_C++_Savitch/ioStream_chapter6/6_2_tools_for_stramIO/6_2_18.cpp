/*
copyint 3 elements between files
*/


#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;


int main(){

    ifstream inStream;
    ofstream outStream;

    inStream.open("infile.dat");
    outStream.open("outfile.dat");

    int first=2, second=3, third=1;

    inStream >> first >> second >> third;

    outStream <<"get the output"<<first + second + third<<endl;
    cout <<"get the output"<<first + second + third<<endl;

    inStream.close();
    outStream.close();

    return 0;
}