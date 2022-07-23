/*
bubble sort using function-pointer
*/

#include<iostream>
using namespace std;

void bubbleSort(int *arr, int n, int(*compare)(int, int));
int compare(int a, int b);

int main(){
    int arr[] = {1, 5, 2, 7, 4};

    bubbleSort(arr, 5, compare);    //in main, just use the name of the function that returns the result
    
    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

void bubbleSort(int *arr, int n, int(*compare)(int, int)){  //function pointer as an argument
    int temp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n-1; j++){
            if(compare(arr[j], arr[j+1]) > 0){  //compare / swap  //int(*compare)(int, int)
                temp = arr[j];  //swap
                arr[j] = arr[j+1];
                arr[j+1] = temp;                
            }
        }
    }
}

int compare(int a, int b){  //CALLBACK function take two integers/compare/return
    if(a>b){
        return 1;
    }else{
        return 0;
    }
}