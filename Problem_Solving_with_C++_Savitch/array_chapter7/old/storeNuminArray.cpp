/*
Q17
*/

#include<iostream>
using namespace std;

const int MAX_NUM = 10;

void readInput(int arr[], int length);

int main(){
    int a[MAX_NUM];
    int length;

    cout<<"Please enter nonnegative integers up to ten: \n";
    
    readInput(a, MAX_NUM);   //automatically get MAX_NUM   ???

    cout<<endl;
    return 0;
}

void readInput(int arr[], int length){
    int inp;
    for(int index = 0; index<length; index++){
        cin>>inp;
        arr[index] = inp;
    }

    for(int index=0; index<length; index++){
        cout<<arr[index]<<" ";
    }
}