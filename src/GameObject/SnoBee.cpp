#include "SnoBee.h"


SnoBee::SnoBee(int x, int y) : GameObject(x, y)
{

}

SnoBee::~SnoBee()
{

}

void SnoBee::update(float dt)
{
    if(this->wasUpdate)
        return;

    this->wasUpdate = true;
}


void SnoBee::draw()
{

}