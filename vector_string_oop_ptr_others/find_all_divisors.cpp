/*
Question 4:
a.
Implement a function:
void printDivisors(int num)
This function is given a positive integer num, and prints all of num’s divisors in an ascending
order, separated by a space.
For Example, if we call printDivisors(100), the expected output is:
1 2 4 5 10 20 25 50 100
 Implementation requirement: Pay attention to the running time of your function. An
  efficient implementation would run in Θ(√𝑛𝑢𝑚).

b.
Use the function above when implementing a program that reads from the user a positive
integer (≥2), and prints all it’s divisors.
Your program should interact with the user exactly as it shows in the following example:
    Please enter a positive integer >= 2: 100
    1 2 4 5 10 20 25 50 100
*/


#include<iostream>
#include<cmath>
using namespace std;

void printDivisors(int num);  //declare void function (function that does not return value)

int main(){
    int inp;

    cout<<"Please enter a positive integer >= 2: "<<endl;    //question b
    cin>>inp;

    printDivisors(inp); //call void function - executable
    cout<<endl;
    
    return 0;
}


//running time: run in Θ(√𝑛𝑢𝑚)
void printDivisors(int num){ //header for void function

    double middlePoint = pow(num, 0.5);  

    for(int i=1; i<middlePoint; i++){   // half down
        if(num%i==0){
            cout<<i<<" ";
        }
    }
    for(int j=middlePoint; j>1; j--){  // half up
        if(num%j==0){
            cout<<num/j<<" ";  //
        }
    }
}