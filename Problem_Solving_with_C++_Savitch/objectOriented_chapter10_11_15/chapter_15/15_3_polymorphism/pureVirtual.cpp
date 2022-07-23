//Poly
// 1. pointer to access to the object
//2. function we are calling is a virtual


#include<iostream>
#include<string>
using namespace std;

class Base{
    private:
       
    public:
        Base(){cout << "this is the Base constructor\n";}
        virtual ~Base(){cout << "this is the Base DEconstructor\n";}

        //PURE VIRTUAL FUNCTION
        virtual string GetClassName() = 0;  //VIRTUAL - SET 0 this does not do anythin. but other functions with the same name-function will do the actual work



};

class Derived : public Base{
    private:
        char* arr;
    public:
        Derived(){arr = new char[0]; cout << "this is the Derived constructor\n";}
        ~Derived() {delete[]arr;   cout << "this is the Derived DEconstructor\n";}

        string GetClassName() override {return "Derived\n";}

};


class Decendant : public Derived{
    private:
        char* arr;
    public:
        Decendant(){arr = new char[0]; cout << "this is the Decendant constructor\n";}
        ~Decendant() {delete[]arr;   cout << "this is the Decendant DEconstructor\n";}

        string GetClassName() override {return "Decendant\n";}

};

void print(Base* obj){
    cout << obj -> GetClassName() <<endl;
}


int main(){
    Derived* derived = new Derived();   //just creating this in heap 
    print(derived);
    delete derived;

    Decendant* decendant = new Decendant();
    print(decendant);
    delete decendant;
    // Base* base = new Base();
    // delete base;    //THIS IS HOW TO CALL THE DECONSTRUCTOR!!!!!!!!
    // cout<<endl;

    // Derived* derived = new Derived();
    // delete derived;
    // cout<<endl;

    // Base* poly = new Derived();
    // delete poly;    //delete poly(Base-object) will only call the base deconstructor, so need it to be virtual
    // cout<<endl;
    return 0;
}