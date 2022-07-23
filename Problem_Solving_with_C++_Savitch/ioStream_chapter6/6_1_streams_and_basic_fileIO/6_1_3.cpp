//include DIRECTIVE
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

int main(){

    //DECLARE
    ifstream fin;
    ofstream fout;

    fin.open("stuff1.dat");
    if(fin.fail()){
        exit(1);
    }

    fout.open("stuff2.dat");
    if(fout.fail()){
        exit(1);
    }

    //CLOSE THESE FILES
    fin.close();
    fout.close();

    return 0;
}