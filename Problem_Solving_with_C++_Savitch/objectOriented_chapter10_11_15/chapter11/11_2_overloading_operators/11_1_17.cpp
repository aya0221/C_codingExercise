#include<iostream>
using namespace std;

class Pairs{
    public:
        Pairs();
        Pairs(int first, int secont);

        friend istream& operator>>(istream& ins, Pairs& second);
        friend ostream& operator<<(ostream& outs, Pairs& second);

    private:
        int f;
        int s;
        
};

istream& operator>>(istream& ins, Pairs& second){
    char temp;

    ins>> temp;
    ins >> second.f;
    ins >> temp;
    ins >> second.s;
    ins>>temp;

    return ins;
}

ostream& operator<<(ostream& outs, Pairs& second){
    outs << '(';
    outs << second.f;
    outs << ',';
    outs<<second.s;
    outs <<')';

    return outs;
}


int main(){
    Paris temp;
    instream(f);

    
    return 0;
}