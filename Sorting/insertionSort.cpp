/*
INSERTION SORT
    Average:O(n^2)
    Best:O(n)
    Worst:O(n^2)
*/

#include<iostream>
using namespace std;

void insertionSort(int A[] , int n);

int main(){
    int A[] = {5, 4, 3, 2, 1};
    insertionSort(A, 5);

    for(int i=0; i<5; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void insertionSort(int A[], int n){
    for(int i=1; i<n; i++){
        int value = A[i];//this will be copied back in later
        int holeIndex = i;

        while(holeIndex > 0 && A[holeIndex -1] > value){
            A[holeIndex] = A[holeIndex - 1];
            holeIndex = holeIndex - 1;
        }
        A[holeIndex] = value;//return the hold value
    }

}