/*
1. Write a function int fib(int n) that returns the n-th element of the Fibonacci
sequence.

2. Write a program that prompts the user to enter a positive integer num, and then
prints the num’s elements in the Fibonacci sequence.
Your program should interact with the user exactly as it shows in the following example:
Please enter a positive integer: 7
13
*/

#include<iostream>
using namespace std;

int fib(int n);  //Function declaration

int main(){   //The main method
    int num;
    int fibonacciNum;

    cout<<"Please enter a positive integer: "<<endl;
    cin>>num;

    fibonacciNum = fib(num);   //assign value in declare function arguments

    cout<<fibonacciNum<<endl;   

    return 0;
}


int fib(int n){ //Function definition - header of the function
        
    //local variable
    int n_2 = 1; //both first and second nums will start with 1
    int n_1 = 1;
    int current; // store the current sum

    int count = 3;  //count the number of addition/ the first loop start from predicting #3rd.

    if(n==1 || n==2){  //the calculation for fibonacci numbers start from sequence #3.
        return 1; 
    }

    while(count<=n){     
        current = n_2 + n_1;
        n_2 = n_1; //update the order 
        n_1 = current; //every time the previous num will b the sum of its previous two numbers
        count++;
    }
    return current;  //return value: "current"
}

