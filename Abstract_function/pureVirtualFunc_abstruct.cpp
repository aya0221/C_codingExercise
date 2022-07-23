/*
PURE VIRTUAL FUNCTION

*/

#include<iostream>
using namespace std;

/* ABSTRACT CLASS */
class Instrument{
    public:
        virtual void makeSound() = 0; //PURE VIRTUAL FUNCTION
};

class Piano : public Instrument{
    public:
        void makeSound(){cout<<"piano\n";}// 
};
class Guitar : public Instrument{
    public:
        void makeSound(){cout<<"guitar\n";}// 
};

int main(){

    /* using BASE-CLASS PTR */
    Instrument* basePtr1 = new Piano();
        // basePtr1->makeSound();

    Instrument* basePtr2 = new Guitar();
        // basePtr2->makeSound();

    /* enable to automate;)) */
    Instrument* arr[2] = {basePtr1, basePtr2};
    for(int i=0; i<2; i++)
        arr[i]->makeSound();

    return 0;
}