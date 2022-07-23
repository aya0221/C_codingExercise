/*
Question 3:
Write a program that reads from the user a positive integer (in a decimal representation), and
prints its binary (base 2) representation.
Your program should interact with the user exactly as it shows in the following example:
Enter decimal number:
76
The binary representation of 76 is 1001100
Implementation Requirements:
1. You are supposed to implement the algorithm that converts to base 2. You should not use
any string or special cout functionalities to make the conversion.
2. You are not allowed to use arrays.
*/

#include<iostream>
#include<string>
using namespace std;

int main(){
    int inp, num;
    string binarry;

    cout<<"Enter decimal number: \n";
    cin>>inp;
    num = inp;

    binarry = "";

    // isDivisible = true;
    while(num != 0){
        binarry = to_string(num % 2) + binarry;
        num = num / 2;
    }
    cout<<"The binary representation of "<<inp<<" is "<<binarry<<endl;
    return 0;
}