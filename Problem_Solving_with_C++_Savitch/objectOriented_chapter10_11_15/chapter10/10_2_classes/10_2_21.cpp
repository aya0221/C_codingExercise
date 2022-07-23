#include<iostream>
using namespace std;

class BankAccount{
    public:

        //store value into private variable
        void set(int dollars, int cents, double rate);
        void set(int dollars, double rate);
        
        //change the values of the private variable
        void update();

        //access to a value in a private variable 
        double getBalance();
        double getRate();

        //output
        void output(ostream& outs);

    private:
        double balance;
        double interestRate;

        double fraction(double percent);
};

void BankAccount::set(int dollars, double rate){
    balance = dollars;
    interestRate = rate;
}

double BankAccount::getRate(){
    return interestRate;
}

void BankAccount::output(ostream& outs){
    outs<<balance<<endl;
    outs<<interestRate<<endl;
}

BankAccount newAccount(BankAccount oldAccount);

int main(){
    BankAccount account1, account2;
    account1.set(2, 5);
    account2 = newAccount(account1);
    account2.output(cout);

    return 0;
}

BankAccount newAccount(BankAccount oldAccount){
    BankAccount temp;
    temp.set(0, oldAccount.getRate());
    return temp;
}