#pragma once
#include "GameObject.h"

class SnoBee : public GameObject
{
    public:
        SnoBee(int x, int y) : GameObject(x, y){}

        void update(float dt){};
};