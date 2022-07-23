/*
Q18 p.458
Write a program that will read up to ten letters into an array and write the letters back to the screen in the reverse order. 

Use a period as a sentinel value to mark the end of the input. 

*/

#include<iostream>
using namespace std;

const int MAX = 10;

void readLetters(char arr[], int length);
void reverseLetters(char arr[], int length);

int main(){
    char a[MAX];

    cout<<"Please enter letters up to 10. "
        <<"end input with a peiod."<<endl;

    readLetters(a, MAX);
    reverseLetters(a, MAX);

    cout<<endl;
    return 0;
}

void readLetters(char arr[], int length){
    char inp;
    int index=0;
    cin>>inp;
    while((inp !='.')&&(index<MAX)){
        arr[index] = inp;
        index++;
        cin>>inp;
    }
}

void reverseLetters(char arr[], int length){
    for(int i=length-1; i>=0; i--){
        cout<<arr[i];
    }
}