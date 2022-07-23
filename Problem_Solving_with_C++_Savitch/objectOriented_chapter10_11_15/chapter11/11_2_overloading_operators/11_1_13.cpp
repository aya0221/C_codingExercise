#include<iostream>
using namespace std;


class Money{
    public:
        friend bool operator ==(const Money& a, const Money& b);

        friend bool operator <=(const Money& a, const Money& b);

        friend Money operator +(const Money& a, const Money& b);
        
        void assign(int temp);
        int getValue();


    private:
        int value;
};

bool operator <=(const Money& a, const Money& b){
    return(a.value <= b.value);
}
bool operator ==(const Money& a, const Money& b){
    return(a.value == b.value);
}

Money operator +(const Money& a, const Money& b){
    Money temp;
    temp.value = a.value + b.value;
    return temp;
}


void Money::assign(int temp){
    value = temp;
}
int Money::getValue(){
    return value;
}

int main(){
    Money temp1, temp2;
    temp1.assign(5);
    temp2.assign(3);

    temp1.getValue() == temp2.getValue();

    return 0;
}