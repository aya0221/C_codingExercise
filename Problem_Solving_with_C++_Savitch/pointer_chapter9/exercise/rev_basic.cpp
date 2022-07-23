//559 type out!

// POINTER is a memory address of a variable
//dinamic variable: variable that are created by using new operator. RETURNS A POINTER
//watch out for dangling pointers 

//array variables are pointer variables

p1 = &variable;
//set the variable p1 equal to the pointer that points to the variable "variable"

int *p1
//the variable pointed to by p1

p1 = new int;   //p1 is a pointer that points to a dinamic variable
delete p1;  //destroy the dinamic variable pointed to by p1 and return the memory used by the dynamic variable to the freestore:


//------------------------------------------------

v1 = 0;
p1= &v1;    //&v1 : address-of operator / refefrence operator - PRODUCE THE POINTER(ADDRESS)
*p1 = 5;
cout<<v1;
cout<<*p1   //*p1 : dereferencing operator - PRODUCE THE VARIABLE IT POINTS TO
//v1 and p1 hold the same value



//------------------------------------------------

typedef int* IntPtr;
IntPtr p;
//is equivalent to 
int *p

//e.g.,
void(IntPtr p);
//this means declaring p as pointer with type int

//------------------------------------------------

typedef double* DoublePtr;
DoublePtr p;
p = new double[10];
delete []p;


//------------------------------------------------

typedef *char CharArray;


int *entry;
entry = new int[10];
for(int i=0; i<10; i++){
    cout<<entry[i];
}
delete []entry;

//------------------------------------------------

for(int i=0; i<arraySize; i++){
    cout<< *(d + i);
}
//is equivalent to
for(int i=0; i<arraySize; i++){
    cout<<d[i];
}
