#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Stundent{
    public:
        string name;
        int id;
};


int main(){

    ifstream instream;
    instream.open("text.txt");

    while(!instream){
        cout<<"failed";
        instream.clear();
        instream.open("text.txt");
    }

    vector<Stundent>vec;

    Stundent obj;

    while(getline(instream, obj.name)){
        instream.ignore(9999, '\t');

        instream >> obj.id;

        vec.push_back(obj);
    }

    for(Stundent s : vec){
        cout<<s.name<<endl;
        cout<<s.id<<endl;
    }

    ofstream outstream;
    outstream.open("out.txt");
    if(outstream.fail()){
        exit(1);
    }

    for(Stundent s: vec){
        outstream << s.id <<" "<< s.name;
    }

    instream.close();
    outstream.close();

    return 0;
}