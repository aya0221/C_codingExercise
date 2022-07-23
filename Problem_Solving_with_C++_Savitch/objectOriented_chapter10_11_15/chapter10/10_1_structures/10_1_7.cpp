#include<iostream>
using namespace std;

struct ShoeType{
    char style;
    int price;

};

//function declaration
void readShoeRecord(ShoeType& newShoe);

//Fills newShoe with values read from the keyboard.
void readShoeRecord(ShoeType& newShoe){
    cin>>newShoe.style;
    cin>>newShoe.price;
}


/*
//STRUCTURE DEFINITION
struct ShoeType{

    //member values
    char style;
    double price;
};

//function declaration
void readShowRecord(ShoeType& newShoe);

int main(){

    //STRUCTURE DECLARATION
    ShoeType temp;  //structure variable , strucure value
    readShowRecord(temp);

    return 0;
}

//function definition
void readShowRecord(ShoeType& newShoe){
    cout<<"style:"<<endl;
    cin>>newShoe.style;
    cout<<"price:"<<endl;
    cin>>newShoe.price;
}

*/