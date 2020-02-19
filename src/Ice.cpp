#include <Ice.h>
#include <SpriteBank.h>
#include <Pengo.h>
#include <Console.h>


void Ice::start(int x, int y)
{
    sprite = SpriteBank::getInstance()->getSprite(2, 708, 0, 16, 16);
    sf::FloatRect gb = sprite.getLocalBounds();
    sprite.setOrigin(gb.width / 2, gb.height / 2);
    this->x = 3*x*gb.width + 24 + gb.width*3/2;
    this->y = 3*y*gb.height + 24 + gb.height*3/2;
    sprite.setPosition(x, y);
    created = true;
}

void Ice::close()
{
    created = false;

}

void Ice::update(float dt)
{
    if(!created)
        return;

    sprite.setPosition(x, y);
    Pengo::getInstance()->window.draw(sprite);
}