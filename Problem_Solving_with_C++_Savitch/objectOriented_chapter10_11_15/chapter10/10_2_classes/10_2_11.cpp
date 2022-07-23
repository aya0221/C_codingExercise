#include<iostream>
using namespace std;

class DayOfYear{
    public:

        //member function
        void input();
        void output();

        //member variable
        int month;
        int day;
};

//definition for the member function "input"

void DayOfYear::input(){
    cout<<"month"<<endl;
    cin>>month;
    cout<<"day"<<endl;
    cin>>day;
}


//TEST CODE
int main(){
    DayOfYear temp;
    temp.input();
    cout<<temp.month<<endl;
    cout<<temp.day<<endl;

    return 0;
}