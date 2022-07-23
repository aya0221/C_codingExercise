/*
input: 20 random integers
output: minimum value, located index
*/

#include<iostream>
using namespace std;

const int LENGTH = 20;

void readInp(int inp, int arr[], int arrSize);
//read 20 integers from user

int minInArray(int arr[], int arrSize);
//given arr, an array of integers, and its logical size

void printIndex(int arr[], int arrSize, int minVal);
//print index for mininum number

int main(){
    int inp;
    int arr[LENGTH];    //array to store input number
    int minValue;

    cout<<"Please enter 20 integers separated by a space: \n";
    readInp(inp, arr, LENGTH);
    

    minValue = minInArray(arr, LENGTH); //call by value
    cout<<"The minimum value is "<<minValue<<", and it is located in the following indices: ";
    printIndex(arr, LENGTH, minValue);
    
    cout<<endl;
    return 0;
}

void readInp(int inp, int arr[], int arrSize){
    for(int i=0; i<arrSize; i++){
        cin>>arr[i];    //store 20 input into an array
    }
}

int minInArray(int arr[], int arrSize){
    int minValue = arr[0];

    for(int i=1; i<arrSize; i++){
        if(minValue > arr[i]){
            minValue = arr[i];
        }
    }
    return minValue;
}

void printIndex(int arr[], int arrSize, int minVal){
    for(int i=0; i<LENGTH; i++){
        if(arr[i] == minVal){
            cout<<i<<" ";
        }
    }
}