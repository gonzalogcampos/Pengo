
#pragma once

#include <SFML/Graphics.hpp>

#include <Level1.h>


class Pengo
{
    private:
        Pengo(){};
        ~Pengo(){};
        Level1 level;
    
    public:
        static Pengo* getInstance()
        {
            static Pengo instance;
            return &instance;
        }

        void Start(void);
        void Run(void);
        void Close(void);

        sf::RenderWindow window;  


        bool K_ESC, K_UP, K_DOWN, K_LEFT, K_RIGHT, K_SPACE, K_G, K_X, K_N; 
};