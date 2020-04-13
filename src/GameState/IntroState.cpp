#include "IntroState.h"
#include <Render.h>
#include <Game.h>


void IntroState::initState()
{
    type = IGameState::INTRO;
    pengo = Render::getInstance()->createSprite("res/T1.png", Rrect(0, 8, 143, 63));
} 


void IntroState::update(float dt)
{
    Render::getInstance()->drawSprite(pengo, Rvect(0, 0), 0.f, 1.f, false);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Game::getInstance()->setState(PLAY);
    }
}


void IntroState::clear(){
    Render::getInstance()->deleteSprite(pengo);
}