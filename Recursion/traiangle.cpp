/*
Q1
    (a): right triangle
    (b): two opposite right triangles
    (c): vertical rule of 2^n -1 lines using more than 1 recursive calls
        Given a positive integer n, and prints a vertical ruler of 2! − 1 lines
        Each line contains ‘-‘ marks as follows:
            • The line in the middle 1/2 of the ruler contains n ‘-‘ marks
            • The lines at the middle of each half (1/4 and 3/4) of the ruler contains (n-1) ‘-‘ marks
            • The lines at the 1/8, 3/8, 5/8 and 7/8 of the ruler contains (n-2) ‘-‘ marks
            • And so on …
            • The lines at the 1/2^k, 2/2^k, 5/2^k ... 2^k-1/2^k of the ruler contains 1 ‘-‘ mark
*/

#include<iostream>
#include<cmath>
using namespace std;

void printTriangle(int n);  // (a)
void printOpositeTriangles(int n);  //(b)
void printRuler(int n); //(c)

int main(){
    int n = 4;
    
    printTriangle(n); // (a)
    printOpositeTriangles(n); //(b)
    printRuler(n); //(c): 

    return 0;
}

//--------(a)--------
void printTriangle(int n){
    if(n == 1){ //base case: if only 1 line
        cout<<'*'<<endl;
    }else{
        printTriangle(n-1);  //make a recursive call: run n-1 time
        for(int i=0; i<n; i++){ //print start for each line
            cout<<'*'<<' ';
        }
        cout<<endl;
    }    
}

//--------(b)--------
void printOpositeTriangles(int n){
    if(n == 1){ //base case: if n is 1
        cout<<'*'<<endl; //belongs to upper shape
        cout<<'*'<<endl; //belongs to bottom shape
    }else{
        for(int i=n; i>0; i--){ //upper shape
            cout<<"* ";
        } cout<<endl;

        printOpositeTriangles(n-1); //make a recursive call: n-1 times

        for(int i=0; i<n; i++){ //bottom shape
            cout<<"* ";
        } cout<<endl;
    }
}

//--------(c)--------
void printRuler(int n){ //(c):

    if(n < 1){  //TERMINATE case
        return; 
    }

    if(n == 1){ //BASE case 
        cout<<"- "<<endl;
    }else{
        printRuler(n-1);    
        for(int i=0; i<n; i++){ //loop each column
            cout<<"- ";
        } cout<<endl;
        printRuler(n -1);
    }
}