/*
OPERATOR:
    - new
    - delete 

HEAP: free store, not keep data.
    (stack/global are vise versa)
*/
#include<iostream>
using namespace std;

int main(){
    int a;  //goes on stack
    int *ptr = NULL;   

    ptr = new int;  //create space in HEAP
    *ptr = 10;  //*ptr = value  -dereferncing
    delete ptr; //free

    ptr = new int[10];  //after deleting, we can reuse the variable neme
    delete []ptr;




    return 0;
}