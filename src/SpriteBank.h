#pragma once

#include <SFML/Graphics.hpp>


class SpriteBank
{
    public:
        void init();
        sf::Sprite getSprite(int texture, int x_init, int y_init, int x_end, int y_end);

        inline static SpriteBank* getInstance()
            {
                static SpriteBank instance;
                return &instance;
            }

    private:
        SpriteBank(){init();}
        sf::Texture T1, T2, T3, T4;



};