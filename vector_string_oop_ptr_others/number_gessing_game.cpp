/*
Question 2:
Implement a number guessing game.
The program should randomly choose an integer between 1 and 100 (inclusive), 
and have the user try to guess that number.

Implementations guidelines:
1. The user can guess at most 5 times.
2. Before each guess the program announces:
• An updated guessing-range, taking in to account previous guesses and responses.
• The number of guesses that the user has left.
3. If the user guessed correctly, the program should announce that, and also tell how many
guesses the user used.
4. If the user guessed wrong, and there are still guesses left, the program should tell the
user if the number (it chose) is bigger or smaller than the number that the user guessed.
5. If the user didn’t guess the number in all of the 5 tries, the program should reveal the
number it chose.
6. Follow the execution examples below for the exact format.
In order to generate random numbers (of type int), 
you should first call the srand function (one time) to initialize a seed for the random number generator. 
Then, you can call the rand function repeatedly to generate random integers.
*/

#include<iostream>
#include <cstdlib>
#include<ctime>

using namespace std;

int main(){
    int guessNum;
    int count = 5;
    bool outOfGuess = false;  //user can only try to guess 5 times
    int myNum;
    int rangeSmall=1, rangeLarge=100; //integer range from 1 to 100

    srand(time(0));    //create the seed for the random number generator
    myNum = (rand() % 100) + 1;  // range of 1-100 

    
    //game start
    cout<<"I thought of a number between 1 and 100! Try to guess it."<<endl;


    while(outOfGuess == false){

        for(int count=5; count>=1; count--){
    
            cout<<"Range: ["<<rangeSmall<<", "<<rangeLarge<<"], Number of guesses left: "<<count<<endl;
            cout<<"Your guess: ";
            cin>>guessNum;

            if(guessNum == myNum){   //correct answer
                cout<<"\nCongrats! You guessed my number in "<<count<< "guesses."<<endl;
            }
            else if(count == 1){  //get out of the loop after 5 guesses
                outOfGuess = true;
                cout<<"Out of guesses! My number is "<<myNum<<endl;
            }

            //try more. giviing hint
            else if(guessNum < myNum){  //wrong answer (too small)
                rangeSmall = guessNum + 1;
                cout<<"Wrong! My number is bigger."<<endl;
                cout<<endl;
            }
            else{
                rangeLarge = guessNum - 1;   //wrong answer (too large)
                cout<<"Wrong! My number is smaller."<<endl;
                cout<<endl;
            }
        }
    }
    cout<<endl;
    return 0;
}




