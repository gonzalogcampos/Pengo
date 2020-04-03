#include "Ice.h"


Ice::Ice(int x, int y) : GameObject(x, y)
{

}

void Ice::update(float dt)
{
    if(this->wasUpdate)
        return;

    this->wasUpdate = true;
}


void Ice::draw()
{

}