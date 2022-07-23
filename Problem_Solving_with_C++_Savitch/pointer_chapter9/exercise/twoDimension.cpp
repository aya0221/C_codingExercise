/*
QUESTIONS
    IntArrayPtr m;
    m = new IntArrayPtr[d1];

*/


#include<iostream>
using namespace std;

typedef int* IntArrayPtr;

int main(){
    int d1, d2;
    
    cout<<"Enter the row and colum dimentions of the array: \n";
    cin>>d1>>d2;

    IntArrayPtr *m = new IntArrayPtr[d1];
    for(int i=0; i<d1; i++){
        m[i] = new int[d2];
    }

    for(int i =0; i<d1; i++){
        for(int j=0; j<d2; j++){
            cin>>m[i][j];
        }
    }

    for(int i=0; i<d1; i++){
        delete []m[i];
    }
    delete []m;

    cout<<endl;
    return 0;
}