//include DIRECTIVE
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void writeInFile(ofstream& outFileInf){
    outFileInf<<"this will be written in out-file"<<endl;
}

int main(){

    //DECLARE
    // ifstream fin;
    // ofstream fout;

    // fin.open("stuff1.dat");
    // if(fin.fail()){
    //     exit(1);
    // }

    // fout.open("stuff2.dat"); //this file will be automatically created
    // if(fin.fail()){
    //     exit(1);
    // }

    //write in file
    ofstream outStream("out.txt");
    writeInFile(outStream);
    // writeInFile(cout);



    return 0;
}