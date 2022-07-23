#ifndef ANT_H
#define ANT_H

#include "Organism.h"
// #include "time.h"

class Ant : public Organism{
    public:
        Ant(char type, int x, int y);
        ~Ant();

        //VIRTUAL FUNK
        void move(Organism* obj[][20], int xVal, int yVal);
        void breed(Organism* obj[][20], int xVal, int yVal);
        // void starve(Organism* obj[][20], int xVal, int yVal);

    private:

};


#endif