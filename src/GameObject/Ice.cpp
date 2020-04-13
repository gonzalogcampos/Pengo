#include "Ice.h"
#include "Map.h"
#include "Render.h"


const float VELOCITY = .2f;
const float TIMEDYING = .15f;

Ice::Ice(int x, int y) : GameObject(x, y)
{
    this->x = x;
    this->y = y;
    sprite = Render::getInstance()->createSprite("res/T2.png", Rrect(708,0,16,16));
    dyingAnimation = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(dyingAnimation, Render::getInstance()->createSprite("res/T2.png", Rrect(708 + 16*0, 48, 16, 16)));
    Render::getInstance()->addFrameToAnimation(dyingAnimation, Render::getInstance()->createSprite("res/T2.png", Rrect(708 + 16*1, 48, 16, 16)));
    Render::getInstance()->addFrameToAnimation(dyingAnimation, Render::getInstance()->createSprite("res/T2.png", Rrect(708 + 16*2, 48, 16, 16)));
    Render::getInstance()->addFrameToAnimation(dyingAnimation, Render::getInstance()->createSprite("res/T2.png", Rrect(708 + 16*3, 48, 16, 16)));
    Render::getInstance()->addFrameToAnimation(dyingAnimation, Render::getInstance()->createSprite("res/T2.png", Rrect(708 + 16*4, 48, 16, 16)));
    Render::getInstance()->addFrameToAnimation(dyingAnimation, Render::getInstance()->createSprite("res/T2.png", Rrect(708 + 16*5, 48, 16, 16)));
    Render::getInstance()->addFrameToAnimation(dyingAnimation, Render::getInstance()->createSprite("res/T2.png", Rrect(708 + 16*6, 48, 16, 16)));
    Render::getInstance()->addFrameToAnimation(dyingAnimation, Render::getInstance()->createSprite("res/T2.png", Rrect(708 + 16*7, 48, 16, 16)));
    Render::getInstance()->addFrameToAnimation(dyingAnimation, Render::getInstance()->createSprite("res/T2.png", Rrect(708 + 16*8, 48, 16, 16)));
}

void Ice::update(float dt)
{
    if(this->wasUpdate)
        return;

    this->wasUpdate = true;

    if(state==STATIC)
        return;

    state_Time += dt;


    if(state_Time>state_Duration)
    {
        state_Time =0.f;
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
            case DYING:
                hasToDie = true;
                break;
        }
    }
}


void Ice::draw()
{
    int delay = (1-(state_Time/VELOCITY))*16;

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
            break;
        case DYING:
            Render::getInstance()->drawAnimation(dyingAnimation, Rvect((x*16+8), (y*16+8)), 0.f, 1.f, false);
            break;
    }
    
}

void Ice::hits(int dir)
{
   switch (dir)
   {
   case 0:
       state = UP;
        state_Duration = VELOCITY;
       state_Time = 0.f;
       y--;
       break;
   case 1:
       state = RIGHT;
        state_Duration = VELOCITY;
       state_Time = 0.f;
       x++;
       break;
   case 2:
       state = DOWN;
        state_Duration = VELOCITY;
       state_Time = 0.f;
       y++;
       break;
   case 3:
       state = LEFT;
        state_Duration = VELOCITY;
       state_Time = 0.f;
       x--;
       break;
   default:
       break;
   }
}

void Ice::dies()
{
    state = DYING;
    state_Time = 0.f;
    state_Duration = TIMEDYING;
}

bool Ice::getHasToDie()
{
    return this->hasToDie;
}