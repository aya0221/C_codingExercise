#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include "Organism.h"

// #include "Ant.h"
// #include "Doodlebug.h"

// #include "time.h"

class GameControl : public Organism{   
    public:
        GameControl();
        ~GameControl();

        // void resetGame();   //called by main
        void playGame();    //called by main
        void showOnDisplay();   //called in GameControl::playGame function


    private:
        
        //SHARE-GAMEBOARD
        Organism* gameBoard[20][20];  //pointer, so the memory address can be directly access/shared in another function
};

#endif