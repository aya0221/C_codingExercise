#include<iostream>
using namespace std;

class Base{
    public:
        virtual void print(){cout<<"base virtual\n";} 
};

class Derived : public Base{
    public:
        void print(){cout<<"derived virtual\n";} 
};


int main(){
    Derived objDerived;
    Base* ptrObjBase = &objDerived;

    ptrObjBase->print();

    return 0;
}