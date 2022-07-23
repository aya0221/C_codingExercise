/*
pow
 - using recursion
 - more efficient theta(log n)
*/

#include<iostream>
#include<cmath>
using namespace std;

int pow(int base, int expo);

int main(){

cout<<pow(2, 3);

return 0;
}


//theta(n)
int pow(int base, int expo){

    //base case
    if(expo == 0){
        return 1;
    }else{
        //make a recursive call
        return ( base * pow(base, --expo));
    }
}

//theta(log n)
int pow(int base, int expo){

    //base case
    if(expo == 0){
        return 1;
    }else{
        //make a recursive call
        if(expo % 2 == 0){
            long x;
            x = pow(base, expo/2);
            return( x * x );
        }else{
            long x;
            x = pow(base, 2/expo);
            return ( x * x * base);
        }
    }
}