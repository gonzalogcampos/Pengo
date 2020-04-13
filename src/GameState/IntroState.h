#pragma once
#include "IGameState.h"

class IntroState : public IGameState 
{
    private:
        unsigned int pengo;
        IntroState(){}         
    public:

         static IntroState* getInstance(){
            static IntroState only_instance;
            return &only_instance;
        }
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
};