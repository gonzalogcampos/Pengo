#include <IntroState.h>
#include <Render.h>
#include <Game.h>


void IntroState::initState()
{
    type = IGameState::INTRO;
    pengo = Render::getInstance()->createSprite("res/T1.png", Rrect(0, 8, 143, 64));
    sega = Render::getInstance()->createSprite("res/T1.png", Rrect(0, 74, 71, 23));
    info = Render::getInstance()->createSprite("res/T1.png", Rrect(0, 200, 80, 19));
} 


void IntroState::update(float dt)
{
    time += dt;
    int i = ((2*time)/1);
    i = i % 2;
    if(i<1)
        drawInfo = true;
    else
        drawInfo = false;
    

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        Game::getInstance()->setState(PLAY);
    }
}

void IntroState::render()
{
    Render::getInstance()->drawSprite(pengo, Rvect(111, 100));
    Render::getInstance()->drawSprite(sega, Rvect(111, 170));

    if(drawInfo)
        Render::getInstance()->drawSprite(info, Rvect(111, 200));
}


void IntroState::clear()
{
    Render::getInstance()->deleteSprite(pengo);
}