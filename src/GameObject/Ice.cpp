#include "Ice.h"
#include "Map.h"
#include "Render.h"


const float VELOCITY = .2f;
const float TIMEDYING = .5f;
const float TIMEEGGVIEW = 10.f;
const float TIMEEGGBREAKING = 1.f;

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


Ice::~Ice()
{
    Render* r = Render::getInstance();
    r->deleteAnimation(dyingAnimation);
    r->deleteAnimation(eggViewAnimation);
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
                    findAlignDiamonds();
                    state = STATIC;
                }
                break;
            case DOWN:
                if(Map::getInstance()->iceMoving(this, 2))
                {
                    y++;
                }else{
                    findAlignDiamonds();
                    state = STATIC;
                }
                break;
            case LEFT:
                if(Map::getInstance()->iceMoving(this, 3))
                {
                    x--;
                }else{
                    findAlignDiamonds();
                    state = STATIC;
                }
                break;
            case RIGHT:
                if(Map::getInstance()->iceMoving(this, 1))
                {
                    x++;
                }else{
                    findAlignDiamonds();
                    state = STATIC;
                }
                break;
            case DYING:
                hasToDie = true;
                break;
            case EGGVIEW:
                state = STATIC;
                break;
            case BREAKING:
                brokenEgg = true;
                break;
            default:
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
            Render::getInstance()->drawSprite(sprite, Rvect((16*x)+8, (16*y)+48), 0.f, 1.f, false);
            break;
        case DOWN:
            Render::getInstance()->drawSprite(sprite, Rvect(x*16+8, (y*16+48)-delay), 0.f, 1.f, false);
            break;
        case UP:
            Render::getInstance()->drawSprite(sprite, Rvect(x*16+8, (y*16+48)+delay), 0.f, 1.f, false);
            break;
        case LEFT:
            Render::getInstance()->drawSprite(sprite, Rvect((x*16+8)+ delay, y*16+48), 0.f, 1.f, false);
            break;
        case RIGHT:
            Render::getInstance()->drawSprite(sprite, Rvect((x*16+8) - delay, y*16+48), 0.f, 1.f, false);
            break;
        case DYING:
            Render::getInstance()->drawAnimation(dyingAnimation, Rvect((x*16+8), (y*16+48)), 0.f, 1.f, false);
            break;
        case EGGVIEW:
            Render::getInstance()->drawAnimation(eggViewAnimation, Rvect((x*16+8), (y*16+48)), 0.f, 1.f, false);
            break;
        case BREAKING:
            Render::getInstance()->drawAnimation(dyingAnimation, Rvect((x*16+8), (y*16+48)), 0.f, 1.f, false);
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
    if(state != DYING && !diamond)
    {
        state = DYING;
        state_Time = 0.f;
        state_Duration = TIMEDYING;
    }
}

bool Ice::getHasToDie()
{
    return this->hasToDie;
}



bool Ice::isEgg()
{
    return egg;
}

void Ice::setEgg()
{
    Render* r = Render::getInstance();

    r->deleteAnimation(dyingAnimation);
    dyingAnimation = r->createAnimation(8);
    r->addFrameToAnimation(dyingAnimation, r->createSprite("res/T2.png", Rrect(708, 65, 16, 16)));
    r->addFrameToAnimation(dyingAnimation, r->createSprite("res/T2.png", Rrect(708, 65+16, 16, 16)));
    r->addFrameToAnimation(dyingAnimation, r->createSprite("res/T2.png", Rrect(708+16, 65+16, 16, 16)));
    r->addFrameToAnimation(dyingAnimation, r->createSprite("res/T2.png", Rrect(708+16*2, 65+16, 16, 16)));

    eggViewAnimation = r->createAnimation(4);
    r->addFrameToAnimation(eggViewAnimation, r->createSprite("res/T2.png", Rrect(708, 65, 16, 16)));
    r->addFrameToAnimation(eggViewAnimation, r->createSprite("res/T2.png", Rrect(708,  0, 16, 16)));

    state = EGGVIEW;
    state_Duration = TIMEEGGVIEW;
    egg = true;
    diamond = false;
}

bool Ice::breakEgg()
{
    if(egg && state == STATIC)
    {
        state_Time = 0.f;
        state_Duration = TIMEEGGBREAKING;
        state = BREAKING;
        return true;
    }
    return false;
}

bool Ice::isBroken()
{
    return brokenEgg;
}

void Ice::showEgg()
{
    state = EGGVIEW;
    state_Duration = 10.f;
}

void Ice::setDiamond()
{
    egg = false;
    diamond  = true;
    sprite = Render::getInstance()->createSprite("res/T2.png", Rrect(708, 16, 16, 16));
}

bool Ice::isDiamond()
{
    return diamond; 
}

void Ice::findAlignDiamonds()
{
    if(diamond)
        Map::getInstance()->testDiamonds(x, y);
}

void Ice::align()
{
    if(diamond)
    {
        sprite = Render::getInstance()->createSprite("res/T2.png", Rrect(708, 32, 16, 16));
    }
}