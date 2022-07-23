/*
P568
programming projects 1
Do Programming Project 7 in Chapter 7 using a dynamic array
use dynamic arrays to store the digit in each large integer
allow an arbitary number of digits instead of capping the number of digits at 20
*/

#include<iostream>
using namespace std;

typedef int* IntegerArrayPointer;   //define a pointer type

int maximumNumberOfDigit;   //global declaration of variable


void readInteger(int* integer, int &lengthOfInteger);
bool calculateSum(int* first, int firstSize, int* second, int secondSize, int* sum, int &sumSize);
void displayInteger(const int* integer, int lengthOfInteger);


int main(){

    //variables declaration
    int lengthOfFirstIntegegr, lengthOfSecondInteger, lengthOfSumOfIntegers;
    char userChoice;

    //declare 3 pointer variables
    IntegerArrayPointer firstInteger, secondInteger, sumInteger;

    do{
        cout<<"Please enter the maximum number of digits in an integer: \n";
        cin>>maximumNumberOfDigit;

        //create 3 dynamic arrays using new operartor
        firstInteger = new int[maximumNumberOfDigit];
        secondInteger = new int[maximumNumberOfDigit];
        sumInteger = new int[maximumNumberOfDigit];

        //
        cout<<"Enter the first number maximum of "
            <<maximumNumberOfDigit<<" digits"<<endl;
        readInteger(firstInteger, lengthOfFirstIntegegr);   //(int-pointer, length will be known after this function)

        cout<<"Enter the first number maximum of "
            <<maximumNumberOfDigit<<" digits"<<endl;
        readInteger(secondInteger, lengthOfSecondInteger);   //(int-pointer, length will be known after this function)

        cout<<"\n The sum of two integers is: \n";

        displayInteger(firstInteger, lengthOfFirstIntegegr);
        displayInteger(secondInteger, lengthOfSecondInteger);

        calculateSum(firstInteger, lengthOfFirstIntegegr, secondInteger, lengthOfSecondInteger, sumInteger, lengthOfSumOfIntegers);

        displayInteger(sumInteger, lengthOfSumOfIntegers);

        cout<<"Would you like to calculate agian? (Y/N): \n";
        cin>>userChoice;
    }while(userChoice == 'Y' || userChoice == 'y');

    delete [] firstInteger, secondInteger, sumInteger;  //delete the dynamic arrays

    return 0;

}


void readInteger(int* integer, int &lengthOfInteger){    //count(number of char will be refered later in another function)
    char ch;
    lengthOfInteger = 0;
    int pos = 0;

    cin.get(ch);    //read the first digit as a character
    while(ch != '\n' && lengthOfInteger<maximumNumberOfDigit){
        *(integer+pos) = (int)ch - (int)'0';  //convert the char into digit and store that digit into a dynamic array
        lengthOfInteger++;
        pos++;
        cin.get(ch);
    }
    if(lengthOfInteger > maximumNumberOfDigit){
        cout<<"The number of digits in this integerg exceeds the maximum number of digits."<<endl;
    }

    //reverse the order of the digits in the array
    for(int i=0; i<lengthOfInteger/2; i++){
        int tempNum = *(integer+i);
        *(integer+i) = *(integer + (lengthOfInteger -i -1));
        *(integer + (lengthOfInteger -i -1)) = tempNum;
    }
}

bool calculateSum(int* first, int firstSize, int* second, int secondSize, int* sum, int &sumSize){
    int sum = 0;
    int carry = 0;
    int i=0;
    int j=0;

    while(i<*count1 && j<*count2 && *size<*length){
        sum = integer1[i] + integer2[j] + carry;

        if(sum > 9){
            carry = sum/10;
            sum = sum % 10;
        }else{
            carry = 0;
        }
        result[*size] = sum;
        size++;
        i++;
        j++;

        if(carry != 0 && *size == *length){
            return false;
        }
    }
    return true;
}

void displayInteger(const int* integer, int lengthOfInteger){
    for(int i = 0; i<lengthOfInteger; i++){
        cout<<integer[i];
    }
}