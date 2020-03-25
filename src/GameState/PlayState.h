#pragma once
#include "IGameState.h"

class PlayState : public IGameState 
{
    private:
        bool loaded; 
        PlayState(){}         
    public:

         static PlayState* getInstance(){
            static PlayState only_instance;
            return &only_instance;
        }
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
};