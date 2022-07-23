#include<iostream>
using namespace std;

struct ShoeType{
    
    //member values
    char style;
    double price;
};

struct Date{

    //member values
    int month; 
    int day;
    int year;
};


//STRUCTURE declaration
struct StockRecord{

    //members
    ShoeType shoeinfo;
    Date arrivalDate;
};

