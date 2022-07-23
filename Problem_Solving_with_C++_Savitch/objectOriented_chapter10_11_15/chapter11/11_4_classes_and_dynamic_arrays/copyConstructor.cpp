/*
if two variable points to the same memory address, 
(i.e. they both are the pointer variable)
the class constructor/deconstructor will be called twice,
but the variable should be already gone when the second-deconstructor is called, 
which is called MEMORY LEAK.
so, in order to avoid it, we create COPY CONSTRUCTOR.
COPY CONSTRUCTOR is called automatially whenever the pointer variable is copied 
e.g.
ClassName a;
ClassName b;
a = b   //this is when the copy-constructor is called



// class Thing{
//     private:
//         int* value;
//     public:
//         Thing(int newVal = 0) : value(new int(newVal)){}
//         ~Thing(){delete []value;}

//         Thing(const Thing& other_rhs) {value = new int(*other_rhs.value);}
//         Thing& operator=(const Thing& other_rhs) {*value = *other_rhs.value;}
// };


*/

#include<iostream>
#include<string>
using namespace std;


class String{
    private:
        char* charArr_private;  //this is just a POINTER, later associated this with new-array
        int length;

    public:
        //CONSTRUCTOR
        String(const char* takenChar){
            length = strlen(takenChar);
            charArr_private = new char[length + 1]; //create the empty heap-array with the size length+1

            memcpy(charArr_private, takenChar, length); //copy the values of array
        }

        //CONSTRUCTOR (another way of writing constructor)
        // String(const char* takenChar)
        // :length(strlen(takenChar)),
        //  charArr_private(new char[length + 1])
        //  {
        //      memcpy(charArr_private, takenChar, length);
        //  }


        //COPY CONSTRUCTOR (automatically called when charArr_private is copied (=) into another variable and both points to the same memory address)
        String(const String& other)
            :length(other.length)
        {
            charArr_private = new char[length + 1];
            memcpy(charArr_private, other.charArr_private, length + 1);
        }

        //DESTRUCTOR (need it since we created "new" in this calss)
        ~String(){
            delete[]charArr_private;    //HEAP will not be deleted automatically (= memory leak)
        }


    char& operator[](int index){    //in order to use []
        return charArr_private[index];
    }

    friend ostream& operator <<(ostream& streamOut, const String& charPtr);    //print charArr_private

};

ostream& operator <<(ostream& streamOut, const String& charPtr){
    streamOut << charPtr.charArr_private <<endl;
    return streamOut;
}

void printString(const String& someString){ //always pass by CONST REFERENCE!!!!!!!!!!! (dont wanna change!)
    cout << someString <<endl;
}

int main(){
    String temp = "happy";
    String copied = temp;   //both points to the SMAE memory address

    copied[2] = 'k';    //in order to use [], need to defined it in class
    

    cout << temp <<endl;    //to print out, (triger the <<), just pass the class-object name
    printString(temp);  //same thing as the previous code

    return 0;
}




/*
// class Thing{
//     private:
//         int* value;
//     public:
//         Thing(int newVal = 0) : value(new int(newVal)){}
//         ~Thing(){delete []value;}

//         Thing(const Thing& other_rhs) {value = new int(*other_rhs.value);}
//         Thing& operator=(const Thing& other_rhs) {*value = *other_rhs.value;}
// };


*/