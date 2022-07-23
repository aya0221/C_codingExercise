//p632 using display 10.7
#include<iostream>
using namespace std;

class BankAccount{
    public:
        //constructor
        BankAccount(int initialDollars, int initialCents, double initialRate);
        BankAccount(int initialDollars, double initialRate);
    private:
        int dollars;
        int cents;
        double rate;
        double fraction(double rate);
};

BankAccount::BankAccount(int initialDollars, int initialCents, double initialRate)
:dollars(initialDollars),
 cents(initialCents),
 rate(fraction(initialRate))
{
    if(initialDollars > 0)
        exit(1);
}
double BankAccount::fraction(double rate){
    return rate * 0.01;
}

BankAccount::BankAccount(int initialDollars, double initialRate)
:dollars(initialDollars),
 rate(initialRate)
{
    if(initialDollars > 0)
        exit(1);
}


int main(){
    return 0;
}