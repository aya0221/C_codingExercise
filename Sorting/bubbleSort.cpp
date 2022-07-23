/*
BUBBLE SORT
    Average:O(n^2)
    Best:O(n)
    Worst:O(n^2)
*/


#include<iostream>
using namespace std;

void bubbleSort(int A[], int lenght);

int main(){
    int A[] = {5, 4, 3, 2, 1};
    bubbleSort(A, 5);
    for(int i=0; i<5; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void bubbleSort(int A[], int n){
    for(int k=1; k < n; k++){
        bool flag = false;
        for(int i=0; i < n-1; i++){
            if(A[i] > A[i+1]){
                swap(A[i], A[i+1]);
                flag = true;
            }
        }
        if(flag == false)
            break;
    }
}