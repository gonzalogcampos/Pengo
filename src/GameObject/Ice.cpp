#include "Ice.h"
#include "Map.h"
#include "Render.h"

#include <iostream>

const float VELOCITY = .2f;

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

    if(state==STATIC)
        return;

    walking_Time += dt;

    if(walking_Time>VELOCITY)
    {
        walking_Time =0.f;
        switch (state)
        {
            case UP:
                if(Map::getInstance()->iceMoving(this, 0))
                {
                    y--;
                }else{
                    state = STATIC;
                }
                break;
            case DOWN:
                if(Map::getInstance()->iceMoving(this, 2))
                {
                    y++;
                }else{
                    state = STATIC;
                }
                break;
            case LEFT:
                if(Map::getInstance()->iceMoving(this, 3))
                {
                    x--;
                }else{
                    state = STATIC;
                }
                break;
            case RIGHT:
                if(Map::getInstance()->iceMoving(this, 1))
                {
                    x++;
                }else{
                    state = STATIC;
                }
                break;    
        }
    }
}


void Ice::draw()
{
    int delay = (1-(walking_Time/VELOCITY))*16;

    switch (state)
    {
        case STATIC:
            Render::getInstance()->drawSprite(sprite, Rvect((16*x)+8, (16*y)+8), 0.f, 1.f, false);
            break;
        case DOWN:
            Render::getInstance()->drawSprite(sprite, Rvect(x*16+8, (y*16+8)-delay), 0.f, 1.f, false);
            break;
        case UP:
            Render::getInstance()->drawSprite(sprite, Rvect(x*16+8, (y*16+8)+delay), 0.f, 1.f, false);
            break;
        case LEFT:
            Render::getInstance()->drawSprite(sprite, Rvect((x*16+8)+ delay, y*16+8), 0.f, 1.f, false);
            break;
        case RIGHT:
            Render::getInstance()->drawSprite(sprite, Rvect((x*16+8) - delay, y*16+8), 0.f, 1.f, false);
    }
    
}

void Ice::hits(int dir)
{
   switch (dir)
   {
   case 0:
       state = UP;
       walking_Time = 0.f;
       y--;
       break;
   case 1:
       state = RIGHT;
       walking_Time = 0.f;
       x++;
       break;
   case 2:
       state = DOWN;
       walking_Time = 0.f;
       y++;
       break;
   case 3:
       state = LEFT;
       walking_Time = 0.f;
       x--;
       break;
   default:
       break;
   } 
}