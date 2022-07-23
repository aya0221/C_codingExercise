/*
program to check if the string is a palindrome or not

cin.getline(char_valuable, length)
    to read the entire line of input char
*/

#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(char* words);
//return true is the string is a palindrome(the same backwords as forwards) and false if it is not

int main(){
    char s1[100];

    cout<<"Enter the string: "<<endl;
    cin.getline(s1, 100);  //cin entire line as an input
    
    if(isPalindrome(s1)){
        cout<<s1<<" is a palindrome"<<endl;
    }else{
        cout<<s1<<" is NOT a palindrome"<<endl;
    }

    cout<<endl;
    return 0;
}

bool isPalindrome(char* words){  //taking the array pointer
    char* front = words;
    char* back = words + strlen(words) - 1; //memory address of the last element in an array

    while(front < back){    //pointers
        if(*front != *back){    //values
            return false;
        }
        front++;    //shift memory address
        back--;
    }
    return true;
}