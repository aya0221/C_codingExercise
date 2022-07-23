/*QUESTION
    int size = sizeof(a) / sizeof(a[0]); //sizeof(&a / sizeof(&a[0])

Is there any way torewrite "a" for this case below?
need to know the memory address of whole array package.
        cout<<"size of a "<<sizeof(a)<<endl;  //4 bit * 5 elements = 20
*/

/*
passing array as function arguments
need to pass the size of the array

array is passed by reference parameter 
copying the address of the variable
*/
#include<iostream>
using namespace std;

int sumOfElements(int a[], int size);

int main(){
    int a[] = {1, 2, 3, 4, 5};  // a == &a[0]  :memory address of a[0]

    //memorry address of a[0]
    cout<<&a[0]<<endl;  
    cout<<a<<endl;  
    cout<<&a<<endl; 
    
    //value of a[0]
    cout<<*a<<endl; 


    cout<<"size of a "<<sizeof(a)<<endl;  //4 bit * 5 elements = 20
    cout<<"size of a[0] "<<sizeof(a[0])<<endl;   //4

    int size = sizeof(a) / sizeof(a[0]); //sizeof(&a / sizeof(&a[0])

    int total = sumOfElements(&a[0], size); //sumOfElements(a, size)

    cout<<total<<endl;

    cout<<endl;
    return 0;
}


int sumOfElements(int* a, int size){   //(int a[])
    int sum = 0;
    for(int i=0; i<size; i++){
        sum += *(a+i);    //a[i]
    }
    return sum;

}