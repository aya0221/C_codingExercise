/*
QUESTION 
how to fix the line of code below?
int (*p)[j] = D; //D = pointers to 1-D array of 3 elements
*/


/*
2-D array
D[i][j]
    i: row
    j:colomn

D : pointer to the first 1D array
----------------------
{{2,3,4}
{7, 8, 9}}
D[0, 1] //this prints 3

-----------------------

D[i][j] = *(D[i] + j)
        = *(*(D+i) + j)
-----------------------

*/
#include<iostream>
using namespace std;

int main(){
    
int D[2][3] = {{2,3,4}, {7, 8, 9}};    //2-D array, array of 1-D array is 3



int (*p)[3] = D; //D = pointers to 1-D array of 3 elements

//all print the memory address of the first element of first Dimention
cout << D <<endl;
cout << *D <<endl;  
cout << D[0] <<endl;
cout << &D[0][0] <<endl;

//print value of row-index 1, column-index 2    !these # are index numbers
cout<< D[1][2]<<endl;
cout<< *(D[1]+ 2) <<endl;       //dereferencing
cout<< *(*(D + 1) + 2) <<endl;


    return 0;
}