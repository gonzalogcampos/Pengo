#include <SpriteBank.h>
#include <Console.h>

void SpriteBank::init()
{
    //Cargo la imagen donde reside la textura del sprite
    if (!T1.loadFromFile("res/T1.png")) {
        console("Error cargando la imagen T1.png\n", 1);
        exit(0);
    }

        //Cargo la imagen donde reside la textura del sprite
    if (!T2.loadFromFile("res/T2.png")) {
        console("Error cargando la imagen T2.png\n", 1);
        exit(0);
    }

        //Cargo la imagen donde reside la textura del sprite
    if (!T3.loadFromFile("res/T3.png")) {
        console("Error cargando la imagen T3.png\n", 1);
        exit(0);
    }

        //Cargo la imagen donde reside la textura del sprite
    if (!T4.loadFromFile("res/T4.png")) {
        console("Error cargando la imagen T4.png\n", 1);
        exit(0);
    }

}


sf::Sprite SpriteBank::getSprite(int texture, int x_init, int y_init, int x_end, int y_end)
{
    sf::Sprite r = sf::Sprite(T1);
    if(texture == 2) r = sf::Sprite(T2);
    else if(texture == 3) r = sf::Sprite(T3);
    else if(texture == 4) r = sf::Sprite(T4);

    r.setTextureRect(sf::IntRect(x_init, y_init, x_end, y_end));
    r.setScale(3,3);

    return r;
}