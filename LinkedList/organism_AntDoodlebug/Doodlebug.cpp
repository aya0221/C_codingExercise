#include "Doodlebug.h"
#include<iostream>
#include "time.h"
using namespace std;

Doodlebug::Doodlebug(char type, int x, int y):Organism(type, x, y){};
Doodlebug::~Doodlebug(){};


//VIRTUAL FUNK
// ===================== [ MOVE ] =====================
void Doodlebug::move(Organism* obj[][20], int xVal, int yVal){
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


if(obj[xVal][yVal]->getType() == 'D'){  //avoid mistakenly being called

    if((newX >= 0) & (newX < 20) & (newY >= 0) & (newY < 20)){
        if((obj[newX][newY] != NULL) && (obj[newX][newY]->getType() == 'A')){   //EAT ants
                    
            //RELEASE(kill) ants
            delete obj[newX][newY]; //release the information of the ant
            obj[newX][newY] = NULL; //reset the new cell = null
            

            //MOVE
            // obj[xVal][yVal] = obj[newX][newY];
            // obj[newX][newY] = obj[xVal][yVal];  //point to the new cell

                    //PLACE DOODLE in NEW CELL
            obj[newX][newY] = new Doodlebug('D', newX, newY);   //CREATE NEW DOODLEBUG
                    // obj[newX][newY]->setNewX(newX);
                    // obj[newX][newY]->setNewY(newY);
                    // obj[newX][newY]->setType('D');
                    // obj[xVal][yVal]->resetTillNextBaby();
                    // obj[xVal][yVal]->resetTillDie();

            
                                                                        // cout<<" RESET"<<endl;
            //RESET OLD CELL
            delete obj[xVal][yVal];
            obj[xVal][yVal] = NULL;
            
            // obj[xVal][yVal]->resetTillNextBaby();
            // obj[xVal][yVal]->resetTillDie();
                                                                                    // cout<<" ATE"<<endl;       

            //SET INF
            // obj[newX][newY]->setType('D');
            // obj[newX][newY]->setNewX(newX);
            // obj[newX][newY]->setNewY(newY);
            // obj[newX][newY]->Increase_tillNextBaby();
            // obj[newX][newY]->Increase_tillDie();

        }else if(obj[newX][newY] == NULL){      //JUST MOVE itself
                                                                                        // cout<<" JUST MOVE"<<endl;  
            //MOVE
            // obj[newX][newY] = obj[xVal][yVal];  //point to the new cell


                //PLACE DOODLE in NEW CELL
                    obj[newX][newY] = new Doodlebug('D', newX, newY);    //CREATE NEW DOODLEBUG
                    // obj[newX][newY]->setNewX(newX);
                    // obj[newX][newY]->setNewY(newY);
                    // obj[newX][newY]->setType('D');
                    // obj[xVal][yVal]->resetTillNextBaby();
                    // obj[xVal][yVal]->resetTillDie();

                                                                                // cout<<" !!!!!!!!!!!"<<endl;  
            //SET NEW INF
            //     obj[newX][newY]->setNewX(newX);
            //     obj[newX][newY]->setNewY(newY);
            // obj[newX][newY]->Increase_tillNextBaby();
            // obj[newX][newY]->Increase_tillDie();

            //RESET OLD CELL
            delete obj[xVal][yVal];                                                                         // cout<<" DELETED"<<endl;  
            obj[xVal][yVal] = NULL;
            // obj[xVal][yVal]->resetTillNextBaby();
            // obj[xVal][yVal]->resetTillDie();
                                                                                        // cout<<" RESET DONE"<<endl;

        }else{   //nowhere to go, so STAY at the current position
            //SET NEW INF
            obj[xVal][yVal]->Increase_tillNextBaby();
            obj[xVal][yVal]->Increase_tillDie();
        }
    }else{
        //RELEASE(kill) ants
        delete obj[xVal][yVal];
        obj[xVal][yVal] = NULL;
    } 

}   
}

// ===================== [ BREED ] =====================
void Doodlebug::breed(Organism* obj[][20], int xVal, int yVal){
    
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
    cout<<"BREED DOODLE<<endl"<<endl;

    //SET INF FOR THE BABY
    obj[newX][newY] = new Doodlebug('D', newX, newY);    //CREATE NEW DOODLEBUG
    // obj[newX][newY]->setNewX(newX);
    // obj[newX][newY]->setNewY(newY);
    // obj[newX][newY]->setType('D');
    // obj[xVal][yVal]->resetTillNextBaby();
    // obj[xVal][yVal]->resetTillDie();
}


// ===================== [ STARVE to DIE] =====================
void Doodlebug::starve(Organism* obj[][20], int xVal, int yVal){
    delete obj[xVal][yVal];
    obj[xVal][yVal] = nullptr;
}