#include<iostream>
#include<ctype.h>    //isDigit()
using namespace std;

class Money{
    public:
        void output(ostream& outs);
        friend ostream& operator<<(ostream& outs, const Money& a);
        
        void output();

        void input(istream& ins);

        void set(double a);

    private:
        double allCents;
        void check(double varidation);
};

//-----------------------------------------
void Money::output(){   //temp.output(); overloading the function name "output"
    output(cout);
}
void Money::output(ostream& outs){  //temp.output(cout);
    outs<<allCents<<endl;
}
//-----------------------------------------

void Money::set(double a){
    allCents = a;
}
//-----------------------------------------
void Money::input(istream& ins){
    // $-9.00    -$9.00
    char oneChar; //$
    char decimalPoint; //-9
    char digit1;    //0
    char digit2;    //0
    double dollars;
    int cents;
    bool isNegative;    //set ture if the input is negative
    
    ins>> oneChar;
    ins>>oneChar>>dollars>>decimalPoint>>digit1>>digit2;
    
    if(dollars<0 || oneChar != '$' || !isdigit(digit1)){
        exit(1);
    }
}

void Money::check(double varidation){
    if(varidation < 1)
        exit(1);
}
//-----------------------------------------
int main(){
    Money temp;
    temp.set(5.0);
    temp.output(cout);
    temp.output();
    return 0;
}