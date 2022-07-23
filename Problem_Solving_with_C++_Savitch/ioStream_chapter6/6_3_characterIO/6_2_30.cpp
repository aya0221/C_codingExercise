#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;

void copyLine(ifstream& inStream);

int main(){

    ifstream inStream;
    inStream.open("../6_2_tools_for_stramIO/file.txt");

    copyLine(inStream);

    inStream.close();

    return 0;
}


void copyLine(ifstream& inStream){
    char next;
    do{
        inStream.get(next);
        cout<<next;
    }
    while(next != '\n');
}