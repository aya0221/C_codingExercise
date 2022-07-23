/*
VIRTUAL FUNCTION
    The most derived version of that function should be executed !!

*/

#include<iostream>
using namespace std;

class Instrument{
    public:
        virtual void makeSound(){cout<<"instrument\n";}//if there is same name of the function in derived class, execute them. if not, execute this
};

class Piano : public Instrument{
    public:
        void makeSound(){cout<<"piano\n";}// the most derived version of the function
};

int main(){
    /* using BASE-CLASS PTR */
    Instrument* basePtr = new Piano();
    basePtr->makeSound();
    return 0;
}