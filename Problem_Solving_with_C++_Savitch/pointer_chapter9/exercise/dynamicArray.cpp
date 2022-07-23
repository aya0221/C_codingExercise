#include<iostream>
using namespace std;

typedef int* IntArrayPtr;

void fillArray(int a[], int size);

void sort(int a[], int size);

int main(){
    int arraySize;
    IntArrayPtr a;

    cout<<"How many numbers will be soreted? \n";
    cin>>arraySize;

    a = new int[arraySize];

    fillArray(a, arraySize);
    sort(a, arraySize);

    cout<<"In soreted order, the numbers are: \n";
    for(int i=0; i<arraySize; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    delete []a;

    return 0;
}



void fillArray(int a[], int size){
    cout<<"Please enter "<<size<<" integers\n";
    for(int i=0; i<size; i++){
        cin>>a[i];
    }
}

void sort(int a[], int size){
    //
}