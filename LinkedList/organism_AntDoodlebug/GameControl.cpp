#include "GameControl.h"
#include "Organism.h"
#include "Doodlebug.h"
#include "Ant.h"

#include<iostream>
using namespace std;

#include "time.h"


// ===================== [ CONSTRUCTOR - RESET / PRODUCE INITIAL DOODLES/ANTS ] =====================
GameControl::GameControl(){
    srand(time(NULL));
    //set ever cells NULL
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            gameBoard[i][j] = NULL;    //avoid mamoery address to be allocated randomly
        }
    }
    //PRODUCE 5-DOODLE
    int doodleProduced = 0;
    while(doodleProduced < 5){
        // srand(time(NULL));
        int xVal = rand() % 20;
        int yVal = rand() % 20;
        
        if(gameBoard[xVal][yVal] == NULL){
            gameBoard[xVal][yVal] = new Doodlebug('D', xVal, yVal);  //pointer = new type (locate on heap)
            // gameBoard[xVal][yVal]->setType('D');
            doodleProduced++;
        }
    }

    //PRODUCE 100-ANT
    int antProduced =0;
    while(antProduced < 100){
        // srand(time(NULL));
        int xVal = rand() % 20;
        int yVal = rand() % 20;
        
        if(gameBoard[xVal][yVal] == NULL){
            gameBoard[xVal][yVal] = new Ant('A', xVal, yVal);  //pointer = new type (locate on heap)
            // gameBoard[xVal][yVal]->setType('A');
            antProduced++;
        }
    }

    this->showOnDisplay();//printOut on display
}

// ===================== [ DEONSTRUCTOR - delete memories located in heap (pointer) ] =====================
GameControl::~GameControl(){
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            delete gameBoard[i][j]; 
        }
    }
}

// ===================== [ PLAY GAME ] =====================
void GameControl::playGame(){   //play game (called by main-func)

    // -------- [ DOODLEBUG ] --------
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){

            if((gameBoard[i][j] != nullptr) && (gameBoard[i][j]->getType() == 'D')){
                    gameBoard[i][j] -> move(gameBoard, i, j);
            }
        }
    }
    // cout<<"move doodle"<<endl;

    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            if((gameBoard[i][j] != nullptr) && (gameBoard[i][j]->getType() == 'D') && (gameBoard[i][j] -> getTillNextBaby() == 9)){
                        gameBoard[i][j] -> breed(gameBoard, i, j);
                                                    // cout<<"doodle breed done"<<endl;
            }
            
        }
    }
    //  cout<<"1 doodle"<<endl;


    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            if((gameBoard[i][j] != nullptr) && (gameBoard[i][j]->getType() == 'D') && (gameBoard[i][j] -> getTillDie() == 3)){//DIE
                        gameBoard[i][j] -> starve(gameBoard, i, j);
                                                // cout<< "FUNK _ DIE DOODLE" <<endl;
            }
        }
    }
    //  cout<<"2 doodle"<<endl;


    // cout<<"done doodle"<<endl;

    // -------- [ ANT ] --------
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            // cout<<"ANT FUNK"<<endl;

            if((gameBoard[i][j] != nullptr) && (gameBoard[i][j]->getType() == 'A')){ //MOVE
                gameBoard[i][j] -> move(gameBoard, i, j);
                                                                                // cout<<"INITIAL"<<endl;
            }

            // if((gameBoard[i][j] != nullptr) && (gameBoard[i][j]->getType() == 'A')){
            //     if(gameBoard[i][j] -> getTillNextBaby() == 3){    //BREED
            //         gameBoard[i][j] -> breed(gameBoard, i, j);
            //         cout<<"SECOND"<<endl;
            //     }
            // }
        }
    }



    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            // cout<<"!!!!!!"<<endl;
            // cout<<"count"<<gameBoard[i][j] -> getTillNextBaby()<<endl;
            if((gameBoard[i][j] != nullptr) && (gameBoard[i][j]->getType() == 'A')&&(gameBoard[i][j] -> getTillNextBaby() == 3)){
                   //BREED
                            gameBoard[i][j] -> breed(gameBoard, i, j);
                            // cout<<"BREED"<<endl;
            }
        }
    }
            

    this->showOnDisplay();//printOut on display
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
} 

// ===================== [ SHOW ON DISPLAY ] =====================
void GameControl::showOnDisplay(){
    for(int i=0; i<20; i++){
        for(int j=0; j<20; j++){
            if(gameBoard[i][j] == NULL){
                cout <<'-'<<" ";
            }else if(gameBoard[i][j]->getType() == 'D'){
                cout << 'X'<<" ";
            }else if(gameBoard[i][j]->getType() == 'A'){
                cout <<'o'<<" ";
            }
        }cout<<endl;
    }cout<<endl;
}