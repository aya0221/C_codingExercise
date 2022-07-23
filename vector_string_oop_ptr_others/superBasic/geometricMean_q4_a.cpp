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

a) First read the length of the sequence.
For example, an execution would look like:
Please enter the length of the sequence: 3
Please enter your sequence:
1
2
3
The geometric mean is: 1.8171
*/

#include<iostream>
#include<cmath>
using namespace std;

int main (){
    int lengthOfSequence, num;
    double geometricMean;
    int product, count;
    double root;

    cout<<"Please enter the length of the sequence: "<<endl;
    cin>>lengthOfSequence;
    cout<<"Please enter your sequence: "<<endl;

    product = 1;
    count = 1;
    while(count <= lengthOfSequence){
        cin>>num;
        product *= num;
        count++;
    }

    root = (double) 1 / lengthOfSequence;
    geometricMean = pow((double)product, root);
    
    cout<<"The geometric mean is: "<<geometricMean<<endl;
    return 0;
}