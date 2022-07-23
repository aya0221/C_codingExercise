//P602
#include<iostream>
using namespace std;

class DayOfYear{
    public:
        void input();
        void output();

        void set(int newMonth, int newDay);

        int getMonth();
        int getDay();
    private:
        void checkDate();   //private member function
        int month;
        int day;
};

void DayOfYear::input(){
    cout<<"month:"<<endl;
    cin>>month;
    cout<<"day:"<<endl;
    cin>>day;
}
void DayOfYear::output(){
    cout<<month<<"/"<<day<<endl;
}
void DayOfYear::set(int newMonth, int newDay){
    month = newMonth;
    day = newDay;
    checkDate();
}
void DayOfYear::checkDate(){
    if(month >12 || month < 1 || day > 31 || day < 1){
        cout<<"illegal date. Aborting program.\n";
        exit(1);
    }
    if(month == 4 || month == 6 || month == 8 || month == 9 || month == 11 && day == 31 ){
        cout<<"illegal date. Aborting program.\n";
        exit(1);
    }
    if(month == 2 && day > 30 ){
        cout<<"illegal date. Aborting program.\n";
        exit(1);
    }
}

int DayOfYear::getMonth(){
    return month;
}
int DayOfYear::getDay(){
    return month;
}

int main(){
    DayOfYear today, birthday;

    //----------input/output values which are stored in private in the class
    cout<<"enter today's date:\n";
    today.input();
    cout<<"today's date you input is:"<<endl;
    birthday.output();

    //----------set up the values into the private variable 
    birthday.set(1, 12);
    cout<<"your birthday is:\n";
    birthday.output();

    //----------
    if(today.getMonth() == birthday.getMonth() && today.getDay() == birthday.getDay())
        cout<<"omg today is your birthday!\n";
    else
        cout<<"cant wait to celebrate your next birthday together!\n";
    

}