//ao2368
//Aya Oshima

/*
 Question 1:
  Write a program that reads a positive integer n from the user and prints out a nxn
 multiplication table. The columns should be spaced by a tab.
*/

#include<iostream>
using namespace std;

int main(){
    int inp;
    int n;
    int printColumn = 1;

    cout<<"Please enter a positive integer:"<<endl;
    cin>>inp;
    n=inp;

    for(int i=1; i<=inp; i++){// rows from 1 to inp-num
        
        for(int j=1; j<=n; j++){  //column
            cout<<printColumn * j;  
            cout<<" ";
        }
        printColumn++;
        cout<<endl;
    } 
    return 0;
}

