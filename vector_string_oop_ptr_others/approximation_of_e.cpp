/*
Question 3:
given a positive integer n, and returns an approximation of e,
calculated by the sum of the first (n+1) addends of the infinite sum.

Notes:
1. running time of eApprox: Θ(𝑛)
2. use a variable of type double to store sum.
*/

#include<iostream>
using namespace std;

double eApprox(int n); //delare function (function returns calculated value)

int main(){
    cout.precision(30);
    int inp;

    for(int n=1; n<=15; n++){
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;    //call the function eApprox() by passing 1 to 15
    }

    return 0;
}

//DEFINITION of the function eApprox()
    //run in Θ(𝑛)
double eApprox(int n){  //header of function

    double sum = 1.0;  //the #1st num is 1
    double top =1.0;

    for(int i=n-1; i>0; i--){  //loop n-1 times for 1/num!
        sum = 1 + top*sum/i;  //add each element to get "e"
    }
    return(sum);   //this is the value to cout
}




/* note----------------------
e^x = 1 + x/1! + x^2/2! + x^3/3! + ...... 
e^x = 1 + (x/1) (1 + (x/2) (1 + (x/3) 

*/