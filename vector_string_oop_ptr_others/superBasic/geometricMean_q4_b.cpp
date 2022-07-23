/*
Question 4:
Write two versions of a program that reads a sequence of positive integers from the user,
calculates their geometric mean, and print the geometric mean.

Notes:
1. In mathematics, geometric mean of a dataset {a1...a^n} containing positive
numbers, is given by: n square a1, a2...a.
For example, the geometric mean of 2, 9 and 12 is equal to 6 (√2 ∙ 9 ∙ 12 " = 6).
2. In order to calculate the n-th root of a number, you should call the pow function, located
in the cmath library.

b) Keep reading the numbers until -1 is entered.
For example, an execution would look like:
Please enter a non-empty sequence of positive integers, each one in a separate line. End your
sequence by typing -1:
1
2
3
-1
The geometric mean is: 1.8171
*/

#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int num;
    double geometricMean;
    int product, count;
    double root;
    bool seenEndOfInput;

    cout<<"Please enter a non-empty sequence of positive integers,"<<endl;
    cout<<"each one in a separate line."<<endl;
    cout<<"End your sequence by typing -1: "<<endl;

    product = 1;
    count = 0;

    seenEndOfInput = false;
    while(seenEndOfInput == false){
        cin>>num;
        if(num != -1){
        product *= num;
        count++;
        }
        else{
            seenEndOfInput = true;
        }
    }

    root = (double)1 / count;
    geometricMean = pow((double)product, root);

    cout<<"The geometric mean is: "<<geometricMean<<endl;
    return 0;
}