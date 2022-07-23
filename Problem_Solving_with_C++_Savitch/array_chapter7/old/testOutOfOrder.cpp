/*
QUESTION
I can not find where this error is coming from...
---------------
(base) ➜  array g++ testOutOfOrder.cpp -o test
testOutOfOrder.cpp:29:1: warning: non-void function does not return a value in all control paths [-Wreturn-type]
}
^
1 warning generated.
---------------

*/


/*
Q16 (p445)
test if the array is out of order
*/
#include<iostream>

int outOfOrder(double s[], int size);

int main(){
    using namespace std;
    int size = 4;
    double valueArray[4] = {1.2, 1.3, 1.4, 1.5};   //[size] ←variable "valueArray" may not be initialized

    cout << outOfOrder(valueArray, size);
    cout << endl;

    return 0;
}

int outOfOrder(double s[], int size){

    for(int index = 0; index < size-1; index++){
        if(s[index] > s[index +1]){  //fetch [i+1] for each i
            return index+1;  
        }else{
            return -1;
        }
    }
}