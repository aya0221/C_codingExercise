#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "Organism.h"

// #include "time.h"

class Doodlebug : public Organism{
    public:
        Doodlebug(char type, int x, int y);
        ~Doodlebug();

        //VIRTUAL FUNK
        void move(Organism* obj[][20], int xVal, int yVal);
        void breed(Organism* obj[][20], int xVal, int yVal);
        void starve(Organism* obj[][20], int xVal, int yVal);

    private:
};


#endif