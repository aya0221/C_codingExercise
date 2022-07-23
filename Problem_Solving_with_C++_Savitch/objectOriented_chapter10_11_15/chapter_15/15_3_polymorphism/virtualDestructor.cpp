#include<iostream>
using namespace std;

class Base{
    private:
       
    public:
        Base(){cout << "this is the Base constructor\n";}
        virtual ~Base(){cout << "this is the Base DEconstructor\n";}

};

class Derived : public Base{
    private:
        char* arr;
    public:
        Derived(){arr = new char[0]; cout << "this is the Derived constructor\n";}
        ~Derived() {delete[]arr;   cout << "this is the Derived DEconstructor\n";}
};


int main(){
    Base* base = new Base();
    delete base;    //THIS IS HOW TO CALL THE DECONSTRUCTOR!!!!!!!!
    cout<<endl;

    Derived* derived = new Derived();
    delete derived;
    cout<<endl;

    Base* poly = new Derived();
    delete poly;    //delete poly(Base-object) will only call the base deconstructor, so need it to be virtual
    cout<<endl;
    return 0;
}