#include<iostream>
using namespace std;

class Money{
    public:
        Money(double amount);
        
        //bool == < > <= >=
        friend bool operator==(const Money a, const Money b);

        //binary operator + - * /
        friend Money operator+(const Money& a, const Money& b);

    private:
        int privateVar;


};

Money::Money(double amount)
:privateVar(amount)
{
}


int main(){
    return 0;
}