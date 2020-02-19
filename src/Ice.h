#pragma once
#include <SpriteBank.h>

class Ice
{
    public:
        sf::Sprite sprite;
        float x, y;
        bool created;

        void start(int x, int y);
        void close();
        void update(float dt);

};