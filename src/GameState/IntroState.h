#pragma once
#include <IGameState.h>

class IntroState : public IGameState 
{
    private:
        unsigned int pengo, sega, info;
        float time = 0.f;
        bool drawInfo = false;
        IntroState();         
    public:

         static IntroState* getInstance(){
            static IntroState only_instance;
            return &only_instance;
        }
        virtual void initState();
        virtual void update(float dt);
        virtual void render();
        virtual void clear();
};