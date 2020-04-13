#pragma once
#include <GameObject.h>


class Ice : public GameObject
{
    private:
        enum iceState{STATIC, UP, DOWN, LEFT, RIGHT, DYING};
        iceState state = STATIC;
        float state_Time = 0.f;
        float  state_Duration = 1.f;
        unsigned int sprite;
        unsigned int dyingAnimation;
        bool hasToDie = false;
    public:  
        Ice(int x, int y);

        ~Ice(){};

        void update(float dt);

        void draw();

        void hits(int dir);

        void dies();

        bool getHasToDie();
};