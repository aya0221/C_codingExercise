/*
//function which returns the pointer (so that the memory will be surely read in another function)

*/

#include<iostream>
using namespace std;

int* func(int* a, int* b);

int main(){ //CALLING FUNCTION
    int a=2, b=4;   //(local to main)

    cout<<"address of a in main function: "
        <<&a<<endl;
    
    int* ptr_c = func(&a, &b);   //call by reference
    cout<<"c: "
        <<*(ptr_c)<<endl;   //dereferncing

    return 0;
}

int* func(int* a, int* b){   //CALLED FUNCTION
    //a,b are pointers to integers local to this func function
    int* c;
    c = new int;    //HEAP(after this function, memory will be

    *c = (*a) + (*b);    //dereferencing 
    
    return c;  //return pointer (memory stored in HEAP not in stack)
    delete c;   //???????????????????????????????????????????????????????????????????????????????
}