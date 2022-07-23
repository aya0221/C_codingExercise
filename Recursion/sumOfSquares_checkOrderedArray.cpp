/*
Q2
    (a):returns the sum of the squares of each of the values in arr.
    (b):return true if the elements in arr are sorted in an ascending order, or false if they are not.
*/

#include<iostream>
#include<cmath>
using namespace std;

int sumOfSquares(int arr[], int arrSize);   //(a)
bool isSorted(int arr[], int arrSize);  //(b)

int main(){
    int intArr[7] = {1, 2, 3, 4, 5, 6, 7}; 

    cout<<sumOfSquares(intArr, 4)<<endl;   //(a)
    cout<<isSorted(intArr, 4)<<endl;   //(b)

    return 0;
}


//=======(a)=======
int sumOfSquares(int arr[], int arrSize){ 
    
    if(arrSize <= 0){//terminate / base case
        return 0;
    }
    if(arrSize == 1){//terminate / base case
        return arr[0];
    }
    
    else{//make a recursive call
        return pow(arr[arrSize-1], 2) + sumOfSquares(arr, arrSize-1);  //return the sum of the squares of each of the values in arr
        
    }
}

//=======(b)=======
bool isSorted(int arr[], int arrSize){

    if(arrSize <= 0){   //base case / terminate
        return false;
    }

    if(arrSize == 1){   //base case / terminate
        return arr[0];
    }
    
    else{  //recursive call
        // cout<<arr[arrSize-1]<<endl;
        return (arr[arrSize-1] >= arr[arrSize-2]);    //return true
        isSorted(arr, arrSize-1);

    }
}