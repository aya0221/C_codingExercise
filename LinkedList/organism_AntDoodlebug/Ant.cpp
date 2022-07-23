#include"Ant.h"
#include<iostream>
using namespace std;

Ant::Ant(char type, int x, int y):Organism(type, x, y){};
Ant::~Ant(){};

//VIRTUAL FUNK
// ===================== [ MOVE ] =====================
void Ant::move(Organism* obj[][20], int xVal, int yVal){
                /* rule for the next direction
                0: up
                1: down
                2: left
                3: up
            */
        srand(time(NULL));
        int newDirection = rand() % 4;
        int newX, newY;
        if(newDirection == 0){
            newX = xVal;
            newY = yVal + 1;
        }else if(newDirection == 1){
            newX = xVal;
            newY = yVal - 1;
        }else if(newDirection == 2){
            newX = xVal - 1;
            newY = yVal;
        }else if(newDirection == 3){
            newX = xVal + 1;
            newY = yVal;
        }



if(obj[xVal][yVal]->getType() == 'A'){
    if((newX >= 0) & (newX < 20) & (newY >= 0) & (newY < 20)){
        if(obj[newX][newY] == NULL){      //JUST MOVE itself

            //MOVE
                // obj[xVal][yVal] = obj[newX][newY];
                // obj[newX][newY] = obj[xVal][yVal];
                    
                    //PLACE ANT in NEW CELL
                    obj[newX][newY] = new Ant('A', newX, newY);    //CREATE NEW DOODLEBUG
                    // obj[newX][newY]->setNewX(newX);
                    // obj[newX][newY]->setNewY(newY);
                    // obj[newX][newY]->setType('A');
                    // obj[xVal][yVal]->resetTillNextBaby();
                    // obj[xVal][yVal]->resetTillDie();
                

            //SET NEW INF
            // obj[newX][newY]->setNewX(newX);
            // obj[newX][newY]->setNewY(newY);
            // obj[newX][newY]->Increase_tillNextBaby();
            // obj[newX][newY]->Increase_tillDie();

            //RESET OLD CELL
            delete obj[xVal][yVal];
            obj[xVal][yVal] = NULL;
            // obj[xVal][yVal]->resetTillNextBaby();
            // obj[xVal][yVal]->resetTillDie();
                // obj[xVal][yVal]->resetTillNextBaby();
                // obj[xVal][yVal]->resetTillDie();

                                                                        //  cout<<"ant MOVED"<<endl;
        }else{       //STAY
            //SET NEW INF
            obj[xVal][yVal]->Increase_tillNextBaby();
            obj[xVal][yVal]->Increase_tillDie();
                                                                            // cout<<"ant STAYED"<<endl;
        }
    }else{
        //RELEASE(kill) ants
        delete obj[xVal][yVal];
        obj[xVal][yVal] = NULL;
    }  
}  
}



// ===================== [ BREED ] =====================
void Ant::breed(Organism* obj[][20], int xVal, int yVal){
    
    //RESET tillBirth for MOM
    obj[xVal][yVal]->resetTillNextBaby(); 

    //PRODUCE NEW BABY in adjacent cell
    int newX, newY;
    if(obj[xVal][yVal + 1] == nullptr){ //up
        newX = xVal;
        newY = yVal + 1;
    }else if(obj[xVal][yVal - 1] == nullptr){   //down
        newX = xVal;
        newY = yVal - 1;
    }else if(obj[xVal - 1][yVal] == nullptr){   //left
        newX = xVal - 1;
        newY = yVal;
    }else if(obj[xVal + 1][yVal] == nullptr){   //right
        newX = xVal + 1;
        newY = yVal;
    }

    //SET INF FOR THE BABY
    obj[newX][newY] = new Ant('A', newX, newY);    //create new ant
    // obj[newX][newY]->setNewX(newX);
    // obj[newX][newY]->setNewY(newY);
    // obj[newX][newY]->setType('A');
    // obj[xVal][yVal]->resetTillNextBaby();

    cout<<"this is breed of ants"<<endl;
}


// ===================== [ STARVE to DIE] =====================
// void Ant::starve(Organism* obj[][20], int xVal, int yVal){
// //
// }