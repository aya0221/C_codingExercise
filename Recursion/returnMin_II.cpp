/*
Q4
    Returns the lowest cost of a game board represented and passed as an array.
        NOTE: The game of “Jump It” consists of a board with n positive integers in a row, 
                except for the first column, which always contains zero. 
                These numbers represent the cost to enter each column.

*/

#include<iostream>
using namespace std;

int jumpIt(int* boards, int n);

int main(){
    int n = 5;
    int boards[6] = {0, 3, 80, 6, 57, 10};

    cout<<jumpIt(boards, n)<<endl;
    return 0;
}

int jumpIt(int* boards, int n){
    if(n <= 0){   //terminate case
        return 0;  
    }
    if(n == 1){   //base case
        return boards[n];   //return one and only element 
    }else{  //recursive case
        if(boards[n-2] < boards[n-1]){
            return boards[n] + jumpIt(boards, n-2);
        }else{
            return boards[n] + jumpIt(boards, n-1);
        }
    }
}