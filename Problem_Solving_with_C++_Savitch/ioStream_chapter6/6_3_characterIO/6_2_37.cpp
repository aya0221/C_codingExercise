#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void func(ifstream& inStream);

int main(){
    ifstream inStream;
    inStream.open("out.txt");

    func(inStream);

    inStream.close();

    return 0;
}



void func(ifstream& inStream){
    char next;
    do{
        inStream.get(next);
        if(!isupper(next)){
            cout << next;
        }
    }
    while(next != '\n');
}