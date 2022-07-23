#include<iostream>
using namespace std;

class Money{
    public:
        friend Money add(const Money& a, const Money& b);
        
        Money(double dollars, int cents);
        Money();

        double getValue() const;

        void output(ostream& outs) const;
        void input(istream& ins);


    private:
        double allCents;
};

Money Add(const Money& a, const Money& b){
    Money temp;
    temp.allCents = a.getValue() + b.getValue();
    return temp;
}

Money::Money()
{
}
Money::Money(double dollars, int cents)
 :allCents(dollars + cents * 0.01)
 {
 }

 double Money::getValue() const{
    return (allCents * 0.01);
 }

void Money::input(istream& ins){
    ins>>allCents;
}

int main(){


    return 0;
}