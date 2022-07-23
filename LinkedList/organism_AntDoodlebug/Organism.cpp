#include"Organism.h"

Organism::Organism(char type, int x, int y)
: type(type),
  tillNextBaby(0),
  tillDie(0)
{
    setNewX(x);
    setNewY(y);
}