#include<iostream>
#include<string>
using namespace std;

int main(){
    string s1, s2;
    // getline(cin, s1) >> s2;  //s2 is same as cin>>s2
    // cout<<"s1"<<s1<<endl;    //s1 aya sora   s2 aya
    // cout<<"s2"<<s2<<endl;

    getline(cin, s1, '!');  //getline(cin, variable, char_delimiter)
    cout<<s1<<endl;

    return 0;
}

