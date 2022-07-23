/*
Test for palindrome property.
*/

#include<iostream>
#include<string>
#include<cctype>    //classify and transform individual characters.

using namespace std;

void swap(char& v1, char& v2);
string reverse(const string& s);
string removePunct(const string& s, const string& punct);
string makeLower(const string& s);
bool isPal(const string& s);

int main(){
    string str;

    cout<<"enter letters followed by pressing return.\n";
    getline(cin, str);  //cin entire line 

    if(isPal(str)){
        cout<<"palindrome";
    }else{
        cout<<"not a palindrome";
    }
    cout<<endl;
    return 0;
}

void swap(char& v1, char& v2){
    char temp = v1;
    v1 = v2;
    v2 = temp;
}

string reverse(const string& s){
    int start = 0;
    int end = s.length();
    string temp(s); //   copy array    string temp = s

    while(start<end-1){
        swap(temp[start], temp[end]);
        start++;
        end--;
    }
    return temp;    //updated array(copied original array and renamed it as temp)
}   
string makeLower(const string& s){
    string temp(s);     //copy original array
    for(int i=0; i<s.length(); i++){
        temp[i] = tolower(s[i]);
    }
    return temp;    //return updated array
}
string removePunct(const string& s, const string& punct){
    string noPunc;  //initialize to empty string
    int sLength = s.length();
    int punctLength = punct.length();

    for(int i; i<sLength; i++){
        string aChar = s.substr(i,1);    //get one char in ith
        int location = punct.find(aChar, 0);    //find character in punct-only array

        if(location < 0 || location >= punctLength){    //if could not find, location becomes not 0
            noPunc += aChar;
        }
        return noPunc;
    }
}
bool isPal(const string& s){
    string punc(",;:!#\" "); //this includes blank
    string str(s);  //copy original array 
    str = makeLower(str);
    string lowerStr = removePunct(str, punc);   //update array

    return(lowerStr == reverse(lowerStr));
}