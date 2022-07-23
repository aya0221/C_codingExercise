#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void textToScreen(ifstream& inStream);


int main(){
    ifstream inStream;
    inStream.open("out.txt");

    textToScreen(inStream);

    inStream.close();
    
    return 0;
}

void textToScreen(ifstream& inStream){
    char next;
    inStream.get(next);
    
    while(! inStream.eof()){
        cout <<next<<endl;
        inStream.get(next);
    }
}