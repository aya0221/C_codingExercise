/*
QUESTION
which while(num < inp) is better??
*/

/*
Question 1:
Write two versions of a program that reads a positive integer n, and prints the first n even
numbers.
a) In the first, use a while loop.
b) In the second, use a for loop.
Each section should interact with the user exactly as it shows in the following example:
Please enter a positive integer: 3
2
4
6
*/

#include<iostream>
using namespace std;

int main(){
    int inp;
    int num = 0;
    int even;

    cout<<"Please enter a positive integer: \n";
    cin>>inp;

    for(num = 1; num <= inp ;num++){
        even = num * 2;
        cout<<even<<endl;
    }
    return 0;
}