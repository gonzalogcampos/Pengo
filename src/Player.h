#pragma once
#include <SFML/Graphics.hpp>
#include <Colider.h>

class Player
{
    public:
        int lifes;
        sf::Sprite sprite;
        Colider colider;
        float x, y;

        void start();
        bool update(float dt);      
};