/*
compare using function pointer and c++ library
*/
#include<iostream>
#include<cmath>
using namespace std;


int compare(const void* a, const void* b);
//

int main(){
    int arr[] = {-31, 22, -1, 50, -6, 4};

    qsort(arr, 6, sizeof(int), compare);   //qsort:c-library.
    //qsort(array-name, sizeOfArray, sizeOfDataType, pointerOfComparison)

    for(int i; i<6; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    return 0;
}


int compare(const void* a, const void* b){
    int A = *((int*)a);  //type casting to int* and getting value 
    int B = *((int*)b);

    return abs(A) - abs(B);  

}