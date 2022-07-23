#include<iostream>
using namespace std;

//STRUCTURE DECLARATION
struct ShoeType{

    //member variables
    char style;
    double price;
};


ShoeType discount(ShoeType oldRecord);

int main(){
    ShoeType temp = {'a', 10};
    
    ShoeType newTemp = discount(temp);

    cout<<newTemp.style<<endl;
    cout<<newTemp.price<<endl;

    return 0;
}

//function definition
//Returns a structure that is the same as its argument,
//but with the price reduced by 10%.

ShoeType discount(ShoeType oldRecord){
    ShoeType funcTemp;

    funcTemp.style = 'h';
    funcTemp.price = oldRecord.price * 0.9;

    return funcTemp;
}