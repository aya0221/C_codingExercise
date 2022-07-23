/*
input: double numbers
read the input and store it into dinamic array
calculate the average and output it
delete the memory allocated to the dynamic array before exiting
*/

#include<iostream>
using namespace std;

typedef double* dynDoubleArray;

int main(){
    int numDoubles;

    dynDoubleArray a;   //a:dynamic array

    cout<<"Input number: \n";
    cin>>numDoubles;
    
    a = new double[numDoubles];

    double sum = 0;
    for(int i=0; i<numDoubles; i++){
        cin>>a[i];
        sum += a[i];
    }
    double average = sum / (double)numDoubles;
    cout<<average;
    
    cout<<endl;

    delete [] a;

    return 0;
}