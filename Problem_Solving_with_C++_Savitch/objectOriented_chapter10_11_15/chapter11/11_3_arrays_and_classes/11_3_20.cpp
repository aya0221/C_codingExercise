#include<iostream>
using namespace std;

class Money{
    public:
        friend istream& operator >>(const istream& ins, const Money& a);
        friend ostream& operator <<(const ostream& outs, const Money& b);
        friend Money operator +(const Money& a, const Money& b);

    private:
        int privateVar;

};

istream& operator >>(istream& ins, Money& a){
    ins >> a;
    return ins;
}
ostream& operator <<(ostream& outs, Money& b){
    outs << b;
    return outs;
}

Money operator +(const Money& a, const Money& b){
    Money temp;
    temp.privateVar = a.privateVar + b.privateVar;
    return temp;
}

int main(){
    Money amount[5];

    for(int i=0; i<5; i++){
        cin >> amount[i];
    }

    for(int i=0; i<5; i++){
        amount[i] = amount[i] + amount[i];
    }

    for(int i=0; i<5; i++){
        cout << amount[i];
    }
    return 0;
}