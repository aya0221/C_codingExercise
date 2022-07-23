/*
char* c : can read all elements in array, but can NOT modify(edit) each elements!!!!
          string gets stored as compile time constant

char c[20]: string gets stored in the space for array. enable to modify

*/
#include<iostream>
using namespace std;

void print(char* c);    //pointer of c  

int main(){

    char c[20] = "hello";   //char array of the length 20 /  store string of length 5 into the char array
    print(c);   //pass memory address of c

    cout<<endl;
    return 0;
}

void print(char* c){    //memory address of c (pointer)
    int i=0;
    while(*c != '\0'){  //DEREFERNCING value of c != space (= end of character)
        cout<<*(c+i);   //DEREFERNCING value of the current address 
        c++;    //increment current memorry address by 1(move to the next block)
    }
    cout<<"\n";
}