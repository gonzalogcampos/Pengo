#pragma once
#include <GameObject.h>

class Ice : public GameObject
{
    public:  
        Ice(int x, int y) : GameObject(x, y){}
        
        void update(float dt){};

};