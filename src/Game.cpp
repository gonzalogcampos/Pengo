#include "Game.h"
#include "Clock.h"
#include "Render.h"
#include "PlayState.h"



void Game::setState(IGameState::stateType type)
{
    switch(type)
    {
        case IGameState::stateType::PLAY:
            state = PlayState::getInstance();
            break;
    }
    state->initState();
}


void Game::run()
{
    setState(IGameState::stateType::PLAY);


    Clock clock;
    while(Render::getInstance()->run())
    {
        if(clock.canContinue())
        {
            float t = clock.getElapsedTime();
            state->update(t);
        }
    }
}

void Game::start()
{  
}