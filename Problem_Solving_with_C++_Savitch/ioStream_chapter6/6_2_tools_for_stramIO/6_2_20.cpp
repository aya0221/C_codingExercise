#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void toScreen(ifstream& fileStream);

int main(){
    ifstream inStream;

    inStream.open("file.txt");
    if(inStream.fail()){
        exit(1);
    }


    toScreen(inStream);

    inStream.close();

    return 0;
}


void toScreen(ifstream& fileStream){
    int next;
    while(fileStream >> next){
        cout << next << endl;
    }
}