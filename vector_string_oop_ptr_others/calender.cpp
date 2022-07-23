/*
input:

output:
- formatted monthly calendar of that month
- return a number 1-7 that represents the day in the week of the last day in that month

- format with header seperated by tab-space
*/

//------------------------------------------
#include<iostream>
#include<cmath>
using namespace std;

const int DAYS_OF_WEEK = 7;
const int NUM_OF_MONTHS = 12;

const int MONTH_28 = 28;
const int MONTH_29 = 29;
const int MONTH_31 = 31;
const int MONTH_30 = 30;


void printYearCalender(int year, int startingDay);
//year: integer representing a year
//startingDay: a number 1-7 that represents the day in the week of Jan/1st

int numOfMonth(int year, int i);

bool checkLeapYear(int year);
//method for determining if a year is a leap year or not
    //divisible by 4 but not by 100 where it is also not divisible by 400.

int lastDay(int numOfDays, int startingDay);

void showCalender(int numOfDays, int StartingDay, int numOfRows);

int printMonthCalender(int numOfDays, int startingDay);
//numOfDays: the number of days in the moonth
//startingDay: a number1-7 that represents the day in the week of the first day in that month
//------------------------------------------

int main(){
    int numOfThisMonth, startingDay, yearInp;

    cout<<"Please enter a year: \n";
    cin>>yearInp;
    cout<<"Please enter the starting day of this month: \n";
    cin>>startingDay;

    printYearCalender(yearInp, startingDay);

    cout<<endl;
    return 0;
}

void printYearCalender(int year, int startingDay){  //print Monthly Calneder
    int numOfThisMonth;
    int i;
    string month[NUM_OF_MONTHS] = {"January", "Feburary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    for(i=0; i<NUM_OF_MONTHS; i++){
        cout<<month[i]<<" "<<year<<endl;
        numOfThisMonth = numOfMonth(year, i);   //passing year and current index
        // printMonthCalender(numOfThisMonth, startingDay);
        showCalender(numOfThisMonth, startingDay, printMonthCalender(numOfThisMonth, startingDay));
        startingDay = lastDay(numOfThisMonth, startingDay)+1; 
        cout<<endl;
    }
}

int numOfMonth(int year, int i){    //check the number of i-month
    int numOfDays;

    if(checkLeapYear(year) == 0){
        if((i+1)%2 == 0){
            if(i == 1){
                numOfDays = MONTH_28;
            }else
            numOfDays = MONTH_30;
        }else{
            numOfDays = MONTH_31;
        }
    }else{
        if((i+1)%2 == 0){
            if(i == 1){
                numOfDays = MONTH_29;   //Feb has only 29 days in leap year
            }else{
                numOfDays = MONTH_30;
            }
        }else{
            numOfDays = MONTH_31;
        }
    }
    return numOfDays;
}

bool checkLeapYear(int year){
    bool leapYear;
    if((year%4 == 0)&&(year%100 != 0)&&(year%400 != 0)){    //checking leap year
        leapYear = true;    //1
    }else{
        leapYear = false;   //0
    }
    return leapYear;
}

int lastDay(int numOfDays, int startingDay){
    int lastDayOfWeek;
    lastDayOfWeek = (numOfDays+startingDay-1)%7;
    return lastDayOfWeek;
}

void showCalender(int numOfDays, int StartingDay, int numOfRows){   //print the calender
    int printFirstRow = 0;
    // int printNum = StartingDay;
    string days[7] = {"Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"};
    for(int i=0; i<DAYS_OF_WEEK; i++){
        cout<<days[i]<<"\t";
    }
    cout<<endl;
    for(int i = 0; i<StartingDay-1; i++){   //empty input
        cout<<" "<<"\t";
    }
    for(int i = StartingDay-1; i<7; i++){   
        printFirstRow++;
        cout<<printFirstRow<<"\t";
    }
    int numAfterSecondRow = printFirstRow;
    cout<<endl;
    for(int i=0; i<numOfRows-1; i++){ //rows.p/out after second line here
        for(int j=0; j<7; j++){ //column
                numAfterSecondRow++;
                if(numAfterSecondRow <= numOfDays){
                    cout<<numAfterSecondRow<<"\t";
                }
        }
        cout<<endl;
    }
}

int printMonthCalender(int numOfDays, int startingDay){ //calculation for the # of rows to print
    int numOfRows;
    double tempNumOfRows;
    tempNumOfRows = (double)(numOfDays + startingDay-1) / 7.0;
    numOfRows = ceil(tempNumOfRows);
    return numOfRows;
}