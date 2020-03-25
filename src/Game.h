#pragma once
#include "IGameState.h"

class Game
{
    private:
        Game(){};
        IGameState* state;
    public:
        static Game* getInstance()
        {
            static Game onlyInstance;
            return &onlyInstance;
        }

        void setState(IGameState::stateType type);
        void start();
        void run();
    
};