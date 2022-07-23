#include<iostream>
using namespace std;

class DayOfYear{
    public:
        DayOfYear(int initalMonth, int initialDay);
        DayOfYear();
        void output(ostream& cout);

    private:
        int month;
        int day;
        void checkDate();
};

DayOfYear::DayOfYear(int initialMonth, int initialDay)
:month(initialMonth),
 day(initialDay)
{
    checkDate();
}

DayOfYear::DayOfYear()
:month(1),
 day(1)
{
}

void DayOfYear::output(ostream& cout){
    cout<<month<<"/"<<day<<endl;
}


void DayOfYear::checkDate(){
    if(month > 12 ||month < 1 || day > 31 || day < 1){
        cout<<"illegal output"<<endl;
        exit(1);
    }
}

int main(){
    DayOfYear temp(1, 5);

    temp.output(cout);
    return 0;
}