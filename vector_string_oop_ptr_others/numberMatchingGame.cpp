/*
output the random digits (0 to 9) stored in array
input the response from user
output if the user response is correct or not
*/

#include <iostream>
#include <cstdlib>
  
using namespace std;

int encryptedPin(int num[]);

const int PIN[5] = {1, 2 ,3, 4, 5}; //array -- this represent positions
const int TOTAL_NUM = 10;

int main() {
    int num[TOTAL_NUM];
    int userInput;

    cout << "Please enter your PIN according to the following mapping:\n"
         << "PIN:\t0 1 2 3 4 5 6 7 8 9\n"
         << "Num:\t";

    for (int i = 0; i < TOTAL_NUM; i++) {
        num[i] = (rand() % 3) + 1;
        cout << num[i] << " ";
    }
    cout<<endl;
    cin >> userInput;

    if (userInput == encryptedPin(num)) {   //call by value
        cout << "Your PIN is correct\n";
    } else {
        cout << "Your PIN is not correct\n";
    }
    return 0;
}

int encryptedPin(int num[]) {
    int encryptedPIN = 0;

    for (int i = 0; i < 5; i++) {
        encryptedPIN = 10 * encryptedPIN + num[PIN[i]]; //incrementing the rank
    }
    return encryptedPIN;
}

