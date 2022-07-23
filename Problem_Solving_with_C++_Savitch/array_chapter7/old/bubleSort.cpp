/*
Sorts an array of integers using Bubble Sort.
*/
#include<iostream>
using namespace std;

void bublesort(int arr[], int length);

int main(){
    int a[]={2, 10, 3, 7, 8, 5};

    bublesort(a, 6);
    for(int index = 0; index < 6; index++){
        cout<< a[index]<<" ";
    }
    cout<<endl;
    return 0;
}

void bublesort(int arr[], int length){
    for(int index = length - 1; index > 0; index--){    //comparing n-1 number of current
        for(int current = 0; current < index; current++){
            if(arr[current] > arr[current + 1]){
                int temp = arr[current+1];
                arr[current+1] = arr[current];
                arr[current] = temp;
            }
        }
    }
}