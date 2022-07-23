/*
 Write a program that, prints a ‘pine tree’ consisting of triangles of increasing sizes, filled
 Your program should interact with the user to read the number of triangles in the tree and the character filling the tree.

a. It prints an n-line triangle, filled with symbol characters, shifted m spaces from the left margin.
b. It prints a sequence of n triangles of increasing sizes (the smallest triangle is a 2-line triangle),
which form the shape of a pine tree. The triangles are filled with the symbol character.
*/



#include<iostream>
using namespace std;

void printShiftedTriangle(int n, int m, char symbol);  
void printPineTree(int n, char symbol); 

int main(){
    int line,space;  //need to declare the type in this function
    char character;

    cout<<"the number of triangles in the tree :"<<endl;
    cin>>line;

    cout<<"character filling the tree: "<<endl;
    cin>>character;

    printPineTree(line, character); //call void function (executable)

    return 0;
}


void printShiftedTriangle(int n, int m, char symbol){   //header of void function

    for(int i=1; i<=n; i++){ //row
        for(int j=1; j<=(n-i)+m; j++){  //m: space gap between the biggest and current trees.
            cout<<" ";
        }
        for(int k=1; k<=2*i-1; k++){
            cout<<symbol;
        }
        cout<<endl;
    }
    return;   //this return is removable
}  

void printPineTree(int n, char symbol){   //header of void function
    for(int k=1; k<=n; k++){
        printShiftedTriangle(k+1, n-k, symbol);  //call function to print a single tree
    }
}