/*
Question 2:
In this question we will use a simplified version of the Roman Numerals System to represent
positive integers.
The digits in this system are I, V, X, L, C, D and M. Each digit corresponds to a decimal value, as
showed in the following table:

Roman digit I V X L C D M
Decimal value 1 5 10 50 100 500 1000

A number in the simplified Roman numerals system is a sequence of Roman digits, which follow
these 2 rules:

1. The digits form a monotonically non-increasing sequence. That is the value of each digit is
less than or equal to the value of the digit that came before it.
For example, DLXXVI is a monotonically non-increasing sequence of Roman digits, but XIV is
not.
2. There is no limit on the number of times that ‘M’ can appear in the number.
‘D’, ‘L’ and ‘V’ can each appear at most one time in the number.
‘C’, ‘X’ and ‘I’ can each appear at most four times in the number.

For example: IIII, XVII and MMMMMMDCCLXXXXVII are legal numbers in our simplified Roman
numeral system, but IIIII, XIV, VVI and CCXLIII are not.
Write a program that reads from the user a (decimal) number, and prints it’s representation in
the simplified Roman numerals system.

Your program should interact with the user exactly as it shows in the following example:
Enter decimal number:
147
147 is CXXXXVII
*/


#include<iostream>
#include<string>
using namespace std;

// Roman digit I V X L C D M
// Decimal value 1 5 10 50 100 500 1000
const int ROMAN_I = 1;
const int ROMAN_V = 5; 
const int ROMAN_X = 10;
const int ROMAN_L = 50;
const int ROMAN_C = 100;
const int ROMAN_D = 500;
const int ROMAN_M = 1000;

int main(){
    int inp;
    int num;
    string romanOutput;
    int remainder = 0;
    char store;

    cout<<"Enter decimal number: \n";
    cin>>inp;
    num = inp;
    cout<<inp<<" is ";

    while(num >= ROMAN_M){
        num -= ROMAN_M;
        cout<<'M';
    }
    while(num >= ROMAN_D){
        num -= ROMAN_D;
        cout<<'D';
    }
    while(num >= ROMAN_C){
        num -= ROMAN_C;
        cout<<'C';
    }
    while(num >= ROMAN_L){
        num -= ROMAN_L;
        cout<<'L';
    }
    while(num >= ROMAN_X){
        num -= ROMAN_X;
        cout<<'X';
    }
    while(num >= ROMAN_V){
        num -= ROMAN_V;
        cout<<'V';
    }
    while(num >= ROMAN_I){
        num -= ROMAN_I;
        cout<<'I';
    }
    cout<<endl;  
    
    return 0;
}

