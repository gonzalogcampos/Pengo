#pragma once
#include <GameObject.h>


class Ice : public GameObject
{
    private:
        enum iceState{STATIC, UP, DOWN, LEFT, RIGHT};
        iceState state = STATIC;
        float walking_Time = 0.f;
        unsigned int sprite;
    public:  
        Ice(int x, int y);

        ~Ice(){};

        void update(float dt);

        void draw();

        void hits(int dir);
};