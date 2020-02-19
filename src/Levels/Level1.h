#pragma once
#include <Level.h>
#include <Ice.h>

class Level1 : public Level
{
    public:
        void start();
        bool update(float dt);
        void close();

        Ice ices[13][15];

    private:
        sf::Sprite background;
};