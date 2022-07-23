#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void copyChar(ifstream& inpStream);


int main(){
    ifstream inpStream;
    inpStream.open("../6_2_tools_for_stramIO/file.txt");

    copyChar(inpStream);    //FILE
    copyChar(cin);

    inpStream.close()[]

    return 0;
}


void copyChar(ifstream& inpStream){
    char ch;
    inpStream.get(ch);
    cout <<ch <<endl;
}