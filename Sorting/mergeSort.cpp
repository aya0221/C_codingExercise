/*
MERGE SORT
    Average:O(nlogn)
    Best:O(nlogn)
    Worst:O(nlogn)
*/

#include<iostream>
using namespace std;

void mergeSort(int array[], int const begin, int const end);
void merge(int array[], int const left, int const mid, int const right);

int main(){
    int A[] = {5, 4, 3, 2, 1};
    int arrSize = sizeof(A) / sizeof(A[0]);
    mergeSort(A, 0, arrSize);

    for(int i=0; i<arrSize; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void mergeSort(int array[], int const begin, int const end){
    /* BASE-case */
    if(begin >= end)
        return;
        
    /* RECURSIVE-case */
    int mid = begin + (end-begin) /2;//memory address 

    mergeSort(array, begin, mid);//LEFT
    mergeSort(array, mid+1, end);//RIGHT

    merge(array, begin, mid, end);//CONCATINATION
}

void merge(int array[], int const left, int const mid, int const right){
    int const lArrSize = mid - left+1;
    int const rArrSize = right - mid;

    /* create new arrays for left / right */
    int *lArr = new int[lArrSize];
    int *rArr = new int[rArrSize];

    /* copy data into new array */
    for(int i=0; i<lArrSize; i++)
        lArr[i] = array[left + i];//array[left + i]
    for(int j=0; j<rArrSize; j++)
        rArr[j] = array[mid + 1 + j];//array[mid + 1 + j]

    /* initial index definition */
    int LarrInd = 0;
    int RarrInd = 0;
    int MergedArrInd = left;

    while(LarrInd < lArrSize && RarrInd < rArrSize){
        if(lArr[LarrInd] <= rArr[RarrInd]){
            array[MergedArrInd++] = lArr[LarrInd++];
        }else{
            array[MergedArrInd++] = rArr[RarrInd++];
        }
    }

    while(LarrInd < lArrSize){
        array[MergedArrInd++] = lArr[LarrInd++];
    }
    while(RarrInd < rArrSize){
        array[MergedArrInd++] = rArr[RarrInd++];
    }
}