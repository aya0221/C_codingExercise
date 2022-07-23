/*
Write some C++ code that will fill an array a with 20 values of type int read in from the keyboard.
You need not write a full program, just the code to do this, 
but do give the declar 
ations for the array and for all variables.
*/

#include<iostream>
using namespace std;

int main(){
    int a[20];
    int inp;
    
    for(int index=0; index<20; index++){
        cin>>inp;
        a[index]=inp;
    }

    for(int i; i<20; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}