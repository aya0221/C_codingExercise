/*
input: random string-word
output:is palindrome or not
*/

#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str);
//given a string word, and returns true if and only if str is a palindrome

void printRes(string word);
//print the result

int main(){
    string inpWord;

    cout<<"Please enter a word: \n";
    cin>>inpWord;

    printRes(inpWord);

    cout<<endl;
    return 0;
}

bool isPalindrome(string str){
    int length;
    string revStr;

    length = str.length();
    for(int i=length-1; i>=0; i--){ //start from element number - 1 
        revStr = revStr + str[i];
    }
    if(str == revStr){
        return 1;
    }else{
        return 0;
    }
}

void printRes(string word){
    if(isPalindrome(word)){
        cout<<word<<" is a palindrome\n";
    } 
    else
        cout<<word<<" is not a palindrome\n";
}
