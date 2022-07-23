//p671
#include<iostream>
using namespace std;

class Money{
    public:
        friend Money subtraction(Money a, Money b);
    private:
        long allCents;
};

Money subtraction(Money a, Money b){
    Money temp;
    temp.allCents = a.allCents - b.allCents;
    return temp;
}