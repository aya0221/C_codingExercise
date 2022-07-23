#include<iostream>
using namespace std;

struct Date{

    //member values
    int month; 
    int day;
    int year;
};

//STRUCTURE DEFINITION
struct StockRecord{
    Date arrivalDate;
};

int main(){
    StockRecord structObj;  //declare a variable of type StockRecord
    structObj.arrivalDate.year = 2022;

    cout<<structObj.arrivalDate.year<<endl;

    return 0;
}