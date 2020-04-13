#include "Game.h"
#include "Clock.h"
#include "Render.h"
#include "PlayState.h"
#include <IntroState.h>


void Game::setState(IGameState::stateType type)
{
    switch(type)
    {
        case IGameState::stateType::PLAY:
            state = PlayState::getInstance();
            break;
        case IGameState::stateType::INTRO:
            state = IntroState::getInstance();
            break;
    }
    state->initState();
}


void Game::run()
{
    setState(IGameState::stateType::INTRO);


    Clock clock;
    while(Render::getInstance()->isWindowOpen())
    {
        if(clock.canContinue())
        {
            float t = clock.getElapsedTime();
            Render::getInstance()->preLoop(t);
            state->update(t);
            Render::getInstance()->postLoop();
        }
    }
}

void Game::start()
{
    Render::getInstance()->init();
}