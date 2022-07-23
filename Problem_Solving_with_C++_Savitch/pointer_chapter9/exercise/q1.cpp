/*
p568 q1
https://www.chegg.com/homework-help/Problem-Solving-with-C--10th-edition-chapter-9-problem-1PP-solution-9780134448282

*/
#include<iostream>
using namespace std;

void addOne(int *ptrNum);
//takes an input as inp_pointer 

int main(){
    int inp = 5;    //integer variable

    addOne(&inp);

    cout<<endl;
    return 0;
}

void addOne(int *ptrNum){
    *ptrNum += 1;
    cout<<*ptrNum; //increment 1
}