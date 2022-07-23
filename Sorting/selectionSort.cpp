/*
SELECTION SORT
    Average:O(n^2)
    Best:O(n^2)
    Worst:O(n^2)
*/

#include<iostream>
using namespace std;

void selectionSort(int A[], int n);

int main(){

    return 0;
}

void selectionSort(int A[], int n){
    for(int i=0; i < n-1; i++){//we need to do n-2 passes
        int minIndex = i;
        
        for(int j=i+1; j<n; j++){
            if(A[j] < A[minIndex]){
                minIndex = j;//update the index of minimum element
            }
        }
        int temp = A[i];//swap the i(smallest element)
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }
}