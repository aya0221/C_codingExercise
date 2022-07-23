//Poly
// 1. pointer to access to the object
//2. function we are calling is a virtual


#include<iostream>
#include<string>
using namespace std;

class Base{
    public:
        virtual string speak() = 0;
};

class Derived : public Base {
    private:

    public:
        string speak(){return "derived is speaking";}
};
class Decendant : public Derived {
    private:

    public:
        string speak(){return "Decendant is speaking";}
};

void print(Base* obj){
    cout << obj -> speak();
}

int main(){
    Base** temp = new Base*[3];   //** HEAP

    temp[0] = new Derived();
    temp[1] = new Decendant();
    temp[2] = new Derived();
    

    for(int i=0; i<3; i++){
        print(temp[i]);
        // temp[i] -> speak();
    }
    return 0;
}