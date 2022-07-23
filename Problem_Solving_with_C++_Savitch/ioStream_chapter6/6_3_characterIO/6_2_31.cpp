#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void sendLine(ofstream& fileStream);

int main(){
    ofstream outStream;
    outStream.open("out.txt");

    sendLine(outStream);

    outStream.close();


    return 0;
}

void sendLine(ofstream& fileStream){
    char ch;
    do{
        cin.get(ch);
        fileStream << ch;
    }
    while(ch != '\n');
    
}