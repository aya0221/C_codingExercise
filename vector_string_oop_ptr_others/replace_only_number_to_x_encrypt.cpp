/*
input: line of text
output: line with all digits in all integers numbers replaced with 'x'
*/
#include <iostream>
#include <string>
using namespace std;

bool isDigit(string word);
string changingString(string word);

int main() {
    string inpString;

    cout<<"Please enter a inpString of text:\n";
    getline(cin, inpString); //cin the entire inpString

    for(int i = 0, j = 0; i <= inpString.length(); i++){  
        if((i == inpString.length()) || (inpString[i] == ' ')){ //if over last word or space
            string word = inpString.substr(i, j - i);
            cout<<changingString(word)<<' ';
            j = i + 1;
        }
    }
    return 0;
}

bool isDigit(string word) {
    for(int i = 0; i < word.length(); i++) {
        if(word[i] < '0' || word[i] > '9') {    //if word is not 1-9
            return false;
        }
    }
    return true;    //if word is only contained with digit
}

string changingString(string word) {
    if(isDigit(word)){
        string newString;

        for(int i = 0; i < word.length(); i++){
            newString += 'x';
        }
        return newString;
    }else{
        return word;
    }
}
