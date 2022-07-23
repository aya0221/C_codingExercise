/*
Question 6:
Write a program that asks the user to input a positive integer n, and print all of the numbers
from 1 to n that have more even digits than odd digits.
For example, if n=30, the program should print:
2
4
6
8
20
22
24
26
28
*/

#include<iostream>
using namespace std;

int main(){
    int num;
    int val;
    int remainder;

    cout<<"Please input a positive integer: "<<endl;
    cin>>num;

    for(int i = 1; i <= num; i++){
    int evenCount = 0, oddCount = 0;
        val = i;
        while(val != 0){
            remainder = val % 10;
            if(remainder % 2 == 0){
                evenCount++;
            }
            else{
                oddCount++;
            }
            val /= 10;
        }
        if(evenCount > oddCount){
            cout<<i<<endl;
        }
    }













    // int num;
    // int remainder, even, odd;
    // int evenOutput;
    // int i, curr, val;


    // even = 0;
    // odd = 0;
    // curr = num;
    // for(i = 2; i <= num; i++){
    //     remainder = curr % 10;
    //     if(remainder % 2 == 0){
    //         even++;
    //     }
    //     else{
    //         odd++;
    //     }
    //     curr = curr / 10;
    // }     
    //             cout<<even<<endl;
    //         cout<<odd<<endl;  
    // if(even>odd){
    // cout<<i<<endl;
    // }






    // for(evenOutput = 2; evenOutput <= num; evenOutput++){
    //     // val = evenOutput;            //QUESTION PART/////////////////
    //         while(evenOutput != 0){
    //             remainder = evenOutput % 10;  ///////////////
    //             if(remainder % 2 == 0){
    //                 even++;
    //             }
    //             else{
    //                 odd++;
    //             }
    //             evenOutput /= 10;
    //         }
    //         // evenOutput = val;               //QUESTION PART/////////////////
    //         if(even > odd){
    //             cout<<evenOutput<<" "<<endl;
    //         }
    //         // cout<<even<<endl;
    //         // cout<<odd<<endl;
    //         // cout<<evenOutput<<endl;
    // }
    return 0;
}