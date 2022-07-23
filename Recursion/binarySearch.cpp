/*
binary search

only look through half set every time
*/


#include<iostream>
using namespace std;

int binarySearch(int* arr, int left, int right, int searchingInt);

int main(){
    int arr[] = {1, 3, 5, 7, 8, 9};

    int right = sizeof(arr) / sizeof(arr[0]);
    cout<<right<<endl;

    cout<<binarySearch(arr, 0, right-1, 5);
    cout<<endl;

    return 0;
}

int binarySearch(int* arr, int left, int right, int searchingInt){

    //base case
    if(left > right){
        return -1;  //if no show
    }

    int mid;
    mid = left + (right - left) / 2;

    if(arr[mid] == searchingInt){
        return mid; //BASE CASE
    }else if(arr[mid] < searchingInt){
        return binarySearch(arr, left, mid-1, searchingInt);
    }else{  //if arr[mid > searcingInt]
        return binarySearch(arr, mid+1, right, searchingInt);
    }
}