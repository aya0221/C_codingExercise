//P609 The class BankAccount is defined in Display 10.5.
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

void BankAccount::set(int dollars, int cents, double rate){
    if((dollars < 0) || (cents < 0) || (rate < 0)){
        cout<<"Illegal values\n";
        return;
    }
    balance = dollars + cents * 0.01;
    interestRate = rate;
}
void BankAccount::set(int dollars, double rate){
    if((dollars < 0) || (rate < 0)){
        cout<<"Illegal values\n";
        return;
    }
    balance = dollars;
    interestRate = rate;
}

void BankAccount::output(ostream& outs){
    outs.setf(ios::fixed);
    outs.setf(ios::showpoint);
    outs.precision(2);
    outs<<"balance: "<<balance<<endl;
    outs<<"interestRate: "<<interestRate<<endl;
}

void BankAccount::update(){
    balance = balance + fraction(interestRate) * balance;
}

double BankAccount::fraction(double percent){
    return (percent / 100.0);
}

double BankAccount::getBalance(){
    return balance;
}

double difference(BankAccount account1, BankAccount account2);


int main(){
    BankAccount account1, account2;

    account1.set(10, 5, 2.0);
    account1.output(cout);

    account1.update();
    cout<<"after update"<<endl;
    account1.output(cout);

    account2 = account1;
    cout<<"account2:"<<endl;
    account2. output(cout);

    cout<<difference(account1, account2);

    return 0;
}

// double difference(BankAccount account1, BankAccount account2){
//     return account1.balance - account2.balance;
// }

double difference(BankAccount account1, BankAccount account2){
    return (account1.getBalance() - account2.getBalance());
}