


#include<iostream>
#include<vector>
using namespace std;

int main(){
    //definition for a type called NumberPtr that will be the type for pointer variables that hold pointers to dynamic variables of type int.
    typedef int* NumberPtr;


    //write a declaration for a pointer variable called my_point that is of type NumberPtr.
    NumberPtr my_point;


    //Write a type definition for pointer variables that will be used to point to dynamic arrays. The array elements are to be of type char. Call the type CharArray.
    typedef char* CharPtr;
    CharPtr CharArray;
    CharArray = new char; 

    //fill the dinamic array with numbers typed in at keybord

    int *entry;
    entry = new int[10];
    for(int i=0; i<10; i++){
        cin>>entry[i];
    }
    
    //destroy the new array
    delete []entry;

    //pointer arithmetic
    int *arr;
    arr = new int[10];
    for(int i; i<10; i++){
        cout<< *(arr + i)<<endl;
        cout<< ++i; //increment - contains the address of the next index
        cout<< --i; //decrement
    }

    return 0;
}