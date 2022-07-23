#include<iostream>
using namespace std;


class DayOfYear{
    public:
        
        friend bool after(DayOfYear date1, DayOfYear date2);

        void input();
        void output();

        int getMonth();
        int getDay();

    private:
        int month;
        int day;
        void checkDate();
};

bool after(DayOfYear date1, DayOfYear date2){
    return (date1.month < date2.month) || date1.month == (date2.month && date1.day < date2.day);
}



int DayOfYear::getMonth(){
    return month;
}
int DayOfYear::getDay(){
    return day;
}


int main(){
    return 0;
}


