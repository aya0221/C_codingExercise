#include<iostream>
using namespace std;

//CLASS DEFINITION
class Temperature{
    public:
        void set(double newDegree, char newScale);
        //Sets the member variables to the values given as //arguments.

        double degrees;
        char scale;
};


//givind a DEFINITION of a member function, so use ::(scope resolution operator)
//definition for the member function "set"
void Temperature::set(double newDegree, char newScale){
    degrees = newDegree; //setting the member variable to the values givcen as an argument
    scale = newScale;
}

int main(){
    return 0;
}
