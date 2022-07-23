//display 6.1 : p345

#include<iostream>
#include<fstream>
#include<cstdlib>   //DIRECTIVE for exit(1)
using namespace std;

int main(){
    ifstream inStream;
    ofstream outStream;

    inStream.open("infile.dat");
    int first = 2, second = 3, third = 1;

    inStream >> first >> second >> third;

    cout<<"the sum is"<<(first + second + third);

    inStream.close();

    return 0;
}