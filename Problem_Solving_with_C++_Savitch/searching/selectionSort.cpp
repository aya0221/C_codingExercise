/*
running time of Selection Search:: T(n) = theta(n^2) ...quadratic
*/
#include<iostream>
using namespace std;

void selectionSort(int arr[], int arrSize);

int findIndexOfMin(int arr[], int low, int high);

int main(){
    int arr[10] = {6, 3, 1, 7, 9, 2};
    selectionSort(arr, 6);

    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void selectionSort(int arr[], int arrSize){
    int i, minInd;
    for(i=0; i<arrSize; i++){
        minInd = findIndexOfMin(arr, i, arrSize);
        swap(arr[i], arr[minInd]);
    }
}

int findIndexOfMin(int arr[], int low, int high){
    int min, minInd;
    min = arr[low];
    minInd = low;

    for(int i=low+1; i<high; i++){
        if(arr[i] < min){
            min = arr[i];
            minInd = i;
        }
    }
    return minInd;
}