#include "GameControl.h"
#include "Organism.h"

#include<iostream>
using namespace std;

int main(){

    GameControl obj;
    // obj.resetGame();    //func in GameControl

    char ch;
    int count=0;
    cout<<"press enter to play the game!"<<endl;
    // cin.get(ch);

    while(cin.get(ch)){
        if(ch == '\n'){
            count++;
            cout<<"No. "<<count<<endl;
            obj.playGame(); //func in GameControl
        }else{
            exit(1);
        }
    }


    return 0;
}