#include "Ice.h"
#include "Map.h"
#include "Render.h"
#include <iostream>

Ice::Ice(int x, int y) : GameObject(x, y)
{
    this->x = x;
    this->y = y;
    sprite = Render::getInstance()->createSprite("res/T2.png", Rrect(708,0,16,16));
}

void Ice::update(float dt)
{
    if(this->wasUpdate)
        return;

    this->wasUpdate = true;
}


void Ice::draw()
{
    Render::getInstance()->drawSprite(sprite, Rvect((16*x)+8, (16*y)+8), 0.f, 1.f, false);
}