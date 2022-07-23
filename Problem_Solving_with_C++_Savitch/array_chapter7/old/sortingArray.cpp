/*
Tests the procedure sort.
*/
#include<iostream>
using namespace std;

//----------------
void fillArray(int a[], int size, int& numberUsed);
void sort(int a[], int numberUsed);
void swapValues(int &v1, int& v2);
int indexOfSmallest(const int a[], int startIndex, int numberUsed);
//----------------

int main(){
    int sampleArray[10];
    int numberUsed;

    cout<<"This program sorts numbers from lowest to highest.\n";
    
    fillArray(sampleArray, 10, numberUsed); //////////////////////////////////can i replace 10 to random variable?

    sort(sampleArray, numberUsed);

    cout<<"In sorted order, the numbers are:\n";
    for(int index=0; index<numberUsed; index++){
        cout<<sampleArray[index]<<" ";
    }

    cout<<endl;
    return 0;
}

void fillArray(int a[], int size, int& numberUsed){
    int inp;
    int index = 0;

    for(index; index < size; index++){
        cin >> inp;
        a[index] = inp;
    }
    numberUsed = index;
}
void sort(int a[], int numberUsed){
    int indexOfNextSmallest;
    int index=0;

    for(index = 0; index <= numberUsed; index++){
        indexOfNextSmallest = indexOfSmallest(a, index, numberUsed);    //index update    
        swapValues(a[index], a[indexOfNextSmallest]);   //value update
    }
    swapValues(a[index], a[indexOfNextSmallest]);   //value update
}
void swapValues(int& v1, int& v2){

}
int indexOfSmallest(const int a[], int startIndex, int numberUsed){
    int min = a[startIndex];    //current looped index
    int indexOfMin = startIndex;

    for(int index = startIndex + 1; index < numberUsed; index++){
        if(a[index] < min){  //if current-index < index+1
        min = a[index]; //update the minimum value
        indexOfMin = index; //update the index where minimum value is stored
        }
    }
    return indexOfMin;
}