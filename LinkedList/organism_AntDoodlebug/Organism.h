#ifndef ORGANISM_H
#define ORGANISM_H

class Organism {
    public:
        Organism(){};   //this default constructor is for GameControl class
        Organism(char type, int x, int y);
        virtual ~Organism(){};


        //PURE VIRTUAL FUNK
        virtual void move(Organism* obj[][20], int xVal, int yVal) {};
        virtual void breed(Organism* obj[][20], int xVal, int yVal) {};
        virtual void starve(Organism* obj[][20], int xVal, int yVal){};

        //ACCESSOR/MUTATORS
            //TYPE
        char getType() const{return this-> type;};
        void setType(char ch){this->type = ch;};

            //X, Y values
        int getX() const{return this-> x;};
        int getY() const{return this-> y;};
        void setNewX(int newX){this->x = newX;};
        void setNewY(int newY){this->y = newY;};

           //BABY
        int getTillNextBaby() const {return this-> tillNextBaby;};
        void Increase_tillNextBaby() {this->tillNextBaby = this->tillNextBaby + 1;};
        void resetTillNextBaby(){this->tillNextBaby = 0;};


            //STARVE to DIE
        int getTillDie() const {return this-> tillDie;};
        void Increase_tillDie() {this->tillDie = this->tillDie + 1;};
        void resetTillDie(){this-> tillDie = 0;};




    private:
        char type;  //'A' or 'D'
        int tillNextBaby;    //3 for ants, 9 for doodle (initial=0 defined in constructor)
        int tillDie;    //3 for ONLY doodle. (initial=0 defined in constructor)

        int x;
        int y;
};

#endif