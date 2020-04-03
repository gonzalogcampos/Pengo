#include "Pengo.h"
#include "Console.h"
#include "Map.h"
#include "Render.h"

const float VELOCITY = .2f;

Pengo::Pengo(int x, int y) : GameObject(x, y)
{
    anim_SD = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(anim_SD, Render::getInstance()->createSprite("res/T3.png",Rrect(0,0,15,15)));
    anim_SU = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(anim_SU, Render::getInstance()->createSprite("res/T3.png",Rrect(0,0,15,15)));
    anim_SL = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(anim_SL, Render::getInstance()->createSprite("res/T3.png",Rrect(0,0,15,15)));
    anim_SR = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(anim_SR, Render::getInstance()->createSprite("res/T3.png",Rrect(0,0,15,15)));
    anim_WD = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(anim_WD, Render::getInstance()->createSprite("res/T3.png",Rrect(0,0,15,15)));
    Render::getInstance()->addFrameToAnimation(anim_WD, Render::getInstance()->createSprite("res/T3.png",Rrect(15,0,15,15)));
    anim_WU = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(anim_WU, Render::getInstance()->createSprite("res/T3.png",Rrect(0,0,15,15)));
    Render::getInstance()->addFrameToAnimation(anim_WU, Render::getInstance()->createSprite("res/T3.png",Rrect(15,0,15,15)));
    anim_WL = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(anim_WL, Render::getInstance()->createSprite("res/T3.png",Rrect(0,0,15,15)));
    Render::getInstance()->addFrameToAnimation(anim_WL, Render::getInstance()->createSprite("res/T3.png",Rrect(15,0,15,15)));
    anim_WR = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(anim_WR, Render::getInstance()->createSprite("res/T3.png",Rrect(0,0,15,15)));
    Render::getInstance()->addFrameToAnimation(anim_WR, Render::getInstance()->createSprite("res/T3.png",Rrect(15,0,15,15)));


    state= S_D;
}

Pengo::~Pengo()
{

}

void Pengo::update(float dt)
{
    if(this->wasUpdate)
        return;

    this->wasUpdate = true;

    if(state == S_D || state == S_U || state == S_L ||state == S_R)
    {

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            if(Map::getInstance()->moveUp(this))
            {
                state = W_U;
                walking_Time = 0.f;
                y--;
            }
            else
            {
                state = S_U;
            }
            

        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            if(Map::getInstance()->moveDown(this))
            {
                state = W_D;
                walking_Time = 0.f;
                y++;
            }
            else
            {
                state = S_D;
            }

        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            if(Map::getInstance()->moveLeft(this))
            {
                state = W_L;
                walking_Time = 0.f;
                x--;
            }            
            else
            {
                state = S_L;
            }

        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {

            if(Map::getInstance()->moveRight(this))
            {
                state = W_R;
                walking_Time = 0.f;
                x++;
            }
            else
            {
                state = S_R;
            }

        }
    }else
    {
        walking_Time += dt;
        if(walking_Time>VELOCITY)
        {
            if(state==W_U)
                state = S_U;
            else if(state == W_D)
                state = S_D;
            else if(state == W_L)
                state = S_L;
            else if(state == W_R)
                state = S_R;
        }
    }
}

void Pengo::draw()
{
    int delay = (1-(walking_Time/VELOCITY))*15;
    switch (state)
    {
    case S_D:
        Render::getInstance()->drawAnimation(anim_SD, Rvect(x*15+8, y*15+8), 0.f, 1.f, false);
        break;
    case S_U:
        Render::getInstance()->drawAnimation(anim_SU, Rvect(x*15+8, y*15+8), 0.f, 1.f, false);
        break;
    case S_L:
        Render::getInstance()->drawAnimation(anim_SL, Rvect(x*15+8, y*15+8), 0.f, 1.f, false);
        break;
    case S_R:
        Render::getInstance()->drawAnimation(anim_SR, Rvect(x*15+8, y*15+8), 0.f, 1.f, false);
        break;
    case W_D:
        Render::getInstance()->drawAnimation(anim_WD, Rvect(x*15+8, (y*15+8)-delay), 0.f, 1.f, false);
        break;
    case W_U:
        Render::getInstance()->drawAnimation(anim_WU, Rvect(x*15+8, (y*15+8)+delay), 0.f, 1.f, false);
        break;
    case W_L:
        Render::getInstance()->drawAnimation(anim_WL, Rvect((x*15+8)+ delay, y*15+8), 0.f, 1.f, false);
        break;
    case W_R:
        Render::getInstance()->drawAnimation(anim_WR, Rvect((x*15+8) - delay, y*15+8), 0.f, 1.f, false);
        break;
    
    default:
        break;
    }
}