#pragma once
#include <GameObject.h>

class Ice : public GameObject
{
    public:  
        Ice(int x, int y);

        ~Ice(){};

        void update(float dt);

        void draw();
};