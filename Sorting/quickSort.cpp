/*
QUICK SORT (pick the pivod, call recursively)
    Average:O(nlogn)
    Best:O(nlogn)
    Worst:O(n^2)
*/

#include<iostream>
using namespace std;

void quickSort(int* A, int start, int end);
int Partition(int *A, int start, int end);

int main(){
    int A[] = {7, 6, 5, 4, 3, 2, 1, 0};
    quickSort(A, 0, 7);
    for(int i=0; i<7; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;

    return 0;
}

void quickSort(int* A, int start, int end){
    if(start < end ){
        int partitionIndex = Partition(A, start, end);//calling partition (smaller# - A[partition] - larger#)
        quickSort(A, start, partitionIndex - 1);//less than pivot (left) keep calling recursively
        quickSort(A, partitionIndex + 1, end);//greater than pivot (right)
    }
}

int Partition(int *A, int start, int end){
    int pivot = A[end];//pick PIVOT
    int partitionIndex = start;//set partition index as start initially
    for(int i=start; i<end; i++){
        if(A[i] <= pivot){
            swap(A[i], A[partitionIndex]);//swap if element is less than pivot
            partitionIndex++;
        }
    }
    swap(A[partitionIndex], A[end]);//swap pivot with element at partition index
    return partitionIndex; //the HALF line where left side is less than A[partitionIndex], and the right side is greater than A[partitionIndex].
}


