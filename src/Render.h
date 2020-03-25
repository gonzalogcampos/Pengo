#pragma once
#include <SFML/Graphics.hpp>


enum Sprites
{
    PENGO,
    ICE,
    SNOBEE
};

class Render
{
    public:
        void init();

        inline static Render* getInstance()
            {
                static Render instance;
                return &instance;
            }

    private:
        Render(){init();}
        sf::Sprite getSprite(int texture, int x_init, int y_init, int x_end, int y_end);

};