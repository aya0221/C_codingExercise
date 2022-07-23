/*
cin.get() is used for accessing character array. 
It includes white space characters. Generally, cin with an extraction operator (>>) terminates when whitespace is found.
However, cin.get() reads a string with the whitespace.

*/
#include<iostream>

using namespace std;

const int MAX_SIZE = 20;

void readInteger(int integer[], int &count);
void reverseInteger(int integer[], int count);
bool addIntegers(int integer1[], int count1, int integer2[], int count2, int result[], int &size);
void displayInteger(int integer[], int &count);


int main(){
    int number1[MAX_SIZE];
    int number2[MAX_SIZE];
    int result[MAX_SIZE];

    int count1 = 0;
    int count2 = 0;
    int size = 0;

    cout<<"Enter the first number: \n";
    readInteger(number1, count1);

    cout<<"Enter the second number: \n";
    readInteger(number2, count2);

    reverseInteger(number1, count1);
    reverseInteger(number2, count2);

    bool success = addIntegers(number1, count1, number2, count2, result, size);

    if(success){
        displayInteger(number1, count1);
        cout<<" + ";
        displayInteger(number2, count2);
        cout<<" = ";
        displayInteger(result, size);
        cout<<endl;
    }

    cout<<endl;
    return 0;
}

void readInteger(int integer[], int &count){
    char ch;

    cin.get(ch);    //////////////////////////////////////
    while(ch != '\n' && count<MAX_SIZE){
        integer[count] = ch - '0';  ////////////////////////////
        count++;
        
        // cin>>ch;
        cin.get(ch);
    }
}

void reverseInteger(int integer[], int count){
    int i = 0;
    int j = count - 1;

    while(i < j){
        int temp = integer[i];
        integer[i] = integer[j];
        integer[j] = temp;
        i++;
        j--;
    }
}

bool addIntegers(int integer1[], int count1, int integer2[], int count2, int result[], int &size){
    int sum = 0;
    int carry = 0;
    int i=0;
    int j=0;

    //create dinamic array
    // char* dinamicARR = 

    while(i<count1 && j<count2 && size<MAX_SIZE){
        sum = integer1[i] + integer2[j] + carry;

        if(sum > 9){
            carry = sum/10;
            sum = sum % 10;
        }else{
            carry = 0;
        }
        result[size] = sum; //size initialized to 0 in main-function
        size++;
        i++;
        j++;

        if(carry != 0 && size ==MAX_SIZE){
            return false;
        }
        
        if(carry != 0 && i<count1 && j<count2){
        size += 1;
        // cout<<size<<endl;
        // result[size] = carry * pow(10, i+1);
        result[size] = carry;   ///////////////////////////////////    ?!?!
    }
    }

    

    return true;
}

void displayInteger(int integer[], int &count){
    for(int i = count-1; i>=0; i--){
        cout<<integer[i];
    }
}