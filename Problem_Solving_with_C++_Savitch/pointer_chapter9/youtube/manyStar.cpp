/*
pointer to pointer

** simply means derefefrencing
*/

#include<iostream>
using namespace std;

int main(){
    int x=5;
    int* p = &x;    //*p : store the address of x       &:adress of the variable

    *p = 6; //dereferencing

    int **q = &p;
    int ***r = &q;

    cout<<*p<<endl; //value stored in p
    cout<<*q<<endl; //value stored in p
    cout<<**q<<endl;    //dereferencing twice *(*q)
    //1. look at *q
    //2. look at *(*q) the value at the address q

    cout<<**r<<endl;    // *(*r)
    cout<<***r<<endl;   // *(*(*r))

    ***r = 7;
    cout<<x<<endl;

    **q = *p + 2;
    cout<<x<<endl;

    return 0;

}