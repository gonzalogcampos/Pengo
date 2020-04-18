#include "IntroState.h"
#include <Render.h>
#include <Game.h>


void IntroState::initState()
{
    type = IGameState::INTRO;
    pengo = Render::getInstance()->createSprite("res/T1.png", Rrect(0, 8, 143, 64));
    sega = Render::getInstance()->createSprite("res/T1.png", Rrect(0, 74, 71, 23));
} 


void IntroState::update(float dt)
{
    Render::getInstance()->drawSprite(pengo, Rvect(111, 100));
    Render::getInstance()->drawSprite(sega, Rvect(111, 170));
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Game::getInstance()->setState(PLAY);
    }
}


void IntroState::clear()
{
    Render::getInstance()->deleteSprite(pengo);
}