/*
running time of Merge Search: T(n) = theta(n log n) ... 
        (recursive)
*/
#include<iostream>
using namespace std;

void mergeSort(int arr[], int low, int high);

void merge(int arr[], int lowLeft, int highLeft, int highRight);

int main(){
    int arr[6] = {6, 3, 1, 7, 9, 2};
    int arrSize = 6;
    mergeSort(arr, 0, arrSize-1);

    for(int i=0; i<6; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}



void mergeSort(int arr[], int low, int high){
    int mid;

    //BASE
    if(low == high)
        return;
    else{
        mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);

    }
}

void merge(int arr[], int lowLeft, int highLeft, int highRight){
    int lowRight = highLeft + 1;
    int size = highRight - lowLeft + 1;

    int *mergedArr = new int[size];

    int iLeft = lowLeft;
    int iRight = lowRight;
    int iRes = 0;
    while(iLeft <= highLeft && iRight <= highRight){
        if(arr[iLeft] < arr[iRight]){
            mergedArr[iRes++] = arr[iLeft++];
        }else{
            mergedArr[iRes++] = arr[iRight++];
        }
    }

    while(iLeft <= highLeft){
        mergedArr[iRes++] = arr[iLeft++];
    }
    while(iRight <= highRight){
        mergedArr[iRes++] = arr[iRight++];
    }

    for(int i=0, iArr = lowLeft;i < size ;i++, iArr++){
        arr[iArr] = mergedArr[i];
    }
    delete[]mergedArr;
}