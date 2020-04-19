#include <Game.h>
#include <Clock.h>
#include <Render.h>
#include <PlayState.h>
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
        float interpolatedTime = clock.getInterpolated();
        Render::getInstance()->preLoop(interpolatedTime);

        if(clock.canContinue())
        {
            Render::getInstance()->events();
            float t = clock.getElapsedTime();
            state->update(t);
        }
        
        state->render();
        Render::getInstance()->postLoop();
    }
}

void Game::start()
{
    Render::getInstance()->init();
}