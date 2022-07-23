#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;


int main(){
    ifstream inStream;
    inStream.open("infile.dat");
    int count = 0, next;

    while(inStream >> next){
        count++;
        cout << next << endl;
    }

    inStream.close();

    return 0;
}