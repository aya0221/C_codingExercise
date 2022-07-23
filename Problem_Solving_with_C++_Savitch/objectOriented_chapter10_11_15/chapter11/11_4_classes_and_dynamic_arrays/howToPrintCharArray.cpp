#include<iostream>
#include<string>
using namespace std;


class CharArr{
    private:
        char* charArr_private;
        int length;


    public:
        CharArr(const char* originalArr){
            length = strlen(originalArr);
            charArr_private = new char[length + 1];
            memcpy(charArr_private, originalArr, length);   //memcpy : c++ tool to copy
        }

    friend ostream& operator<<(ostream& outs, const CharArr& charArr);  //pass TYPE NAME 

};

ostream& operator<<(ostream& outs, const CharArr& charArr){
    outs << charArr.charArr_private <<endl;
    return outs;
}

int main(){
    CharArr temp = "happy";
    cout << temp << endl;
    return 0;
}