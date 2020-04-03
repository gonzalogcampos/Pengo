#pragma once
#include "GameObject.h"

class SnoBee : public GameObject
{
    public:
        SnoBee(int x, int y);
        ~SnoBee();

        void update(float dt);

        void draw();
};