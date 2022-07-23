//If a class definition involves pointers and dynamically allocated memory using the new operator,
//then you need to include a copy constructor.

#include<iostream>
using namespace std;

class StringVar{
    public:
        StringVar(int size);
        StringVar();
        
        StringVar(const char a[]);
        // StringVar(const char* a);    same as the previous line
        StringVar(const StringVar& stringObj);

        ~StringVar();

        int length() const;

        void inputLine(istream& ins);
        friend ostream& operator <<(ostream& outs, const StringVar& theString);

        void operator =(const StringVar& rhs);  //=(appending operator) SHOULD NOT BE FRIEND!



    private:
        char* privatePtr;
        int maxLength;
};

void conversation(int maxNameSize);

StringVar::StringVar()
:maxLength(100)
{
    privatePtr = new char[maxLength + 1];
    privatePtr[0] = '\0';
}

StringVar::StringVar(int size)
:maxLength(size)
{
    privatePtr = new char[maxLength + 1];
    privatePtr[0] = '\0';
}

StringVar::StringVar(const char a[])
:maxLength(strlen(a))
{
    privatePtr = new char[maxLength + 1];
    strcpy(privatePtr, a);
}

StringVar::StringVar(const StringVar& stringObj)
:maxLength(stringObj.length())
{
    privatePtr = new char[maxLength + 1];
    strcpy(privatePtr, stringObj.privatePtr);
}

StringVar::~StringVar() //DSTRUCTOR
{
    cout<<endl
        <<"bue"<<endl;
    delete[] privatePtr;

    // delete [] privatePtr;
}

int StringVar::length() const{
    return strlen(privatePtr);
}

void StringVar::inputLine(istream& ins){
    ins.getline(privatePtr, maxLength + 1);
}

ostream& operator<<(ostream& outs, const StringVar& a){
    outs << a.privatePtr;
    return outs;
}

void StringVar::operator =(const StringVar& rhs){
    int newLength = strlen(rhs.privatePtr);

    if(newLength > maxLength){
        delete [] privatePtr;
        maxLength = newLength;
        privatePtr = new char[maxLength + 1];
    }
    for(int i=0; i < newLength; i++){
        privatePtr[i] = rhs.privatePtr[i];
    }
    privatePtr[newLength] = '\0';
}

void conversation(int maxNameSize);

int main(){

    conversation(5);

    cout<<"end"<<endl;  //this will be the LAST output (even after the deconstructor)
    return 0;
}

void conversation(int maxNameSize){
    StringVar temp_int(maxNameSize), tempStr("happy");
    cout<<"what is your name"<<endl;
    temp_int.inputLine(cin);
    cout << tempStr <<endl;
    cout << temp_int;
}





