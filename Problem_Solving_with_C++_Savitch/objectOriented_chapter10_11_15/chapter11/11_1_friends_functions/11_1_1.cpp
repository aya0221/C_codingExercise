//p657
#include<iostream>
using namespace std;

class DayOfYear{
    public:
        DayOfYear(int theMonth, int theDay);

        void input();
        void output();

        int getMonth();
        int getDay();

    private:
        int month;
        int day;
        void checkDate();
};

int DayOfYear::getMonth(){
    return month;
}
int DayOfYear::getDay(){
    return day;
}

bool before(DayOfYear date1, DayOfYear date2);

int main(){
    return 0;
}

bool before(DayOfYear date1, DayOfYear date2){
    return (date1.getMonth() < date2.getMonth()) || date1.getMonth() == (date2.getMonth() && date1.getDay() < date2.getDay());
}

