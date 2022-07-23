#include<iostream>
using namespace std;


class Percent{
    public:
        friend bool operator ==(const Percent& first, const Percent& second);
        friend bool operator <(const Percent& first, const Percent& second);

        Percent();
        Percent(int a);

        friend istream& operator>>(istream& ins, Percent& theObject);
        friend ostream& operator<<(ostream& outs, Percent& theObject);
    private:
        int privateVar;
};

istream& operator>>(istream& ins, Percent& theObject){
    char temp;
    ins >> theObject.privateVar;    //assume input: 10% 99% etc.

    ins >> temp;    //%
    return ins;
        
}

ostream& operator<<(ostream& outs, Percent& theObject){
    outs << theObject.privateVar << '%';
    return outs;
}


//definition
// bool operator ==(const Percent& first, const Percent& second){

// }


// bool operator <(const Percent& first, const Percent& second){

// }

int main(){
    return 0;
}