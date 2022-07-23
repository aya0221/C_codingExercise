/*
Q3
    Return the minimum value in that sequence
    version 1:find the minimum value out of all the elements in positions: 0, 1, 2, …, arrSize-1.
    version 2: find the minimum value out of all the elements in positions: low, low+1, …, high.
*/

#include<iostream>
using namespace std;

int minInArray1(int arr[], int arrSize);    //(1)
int minInArray2(int arr[], int low, int high);  //(2)

int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 4, -9, 15};
    int res1, res2, res3, res4;

    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout<<res1<<" "<<res2<<endl; //should both be -9
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2])
    cout<<res3<<" "<<res4<<endl; //should both be 3
    return 0;
}

//=======(1)=======
int minInArray1(int arr[], int arrSize){    //find the min out of all the elements in positions
    if(arrSize == 1){   //base case
        return arr[0];   //terminate
    }else{  //recursive call
        minInArray1(arr, arrSize-1);
        if(arr[arrSize-1] < arr[arrSize-2]){
            return arr[arrSize-1];  //return min value
        }else{
            return arr[arrSize-2];  //return min value
        }
    }
}

//=======(2)=======
int minInArray2(int arr[], int low, int high){  // low/high:indices 
    if(low == high){   //if only one element in array
        return arr[0];  //return one and only element
    }else{  //recursive call
        int prevInt = minInArray2(arr, low+1, high);
        int min;
        if(arr[low] < prevInt){
            min = arr[low];
        }else{
            min = prevInt;
        }
        return min;
    }
}