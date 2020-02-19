#include <Player.h>
#include <SpriteBank.h>
#include <Pengo.h>
#include <Console.h>


void Player::start()
{
    lifes = 3;

    x = 0.f;
    y = 0.f;

    sprite = SpriteBank::getInstance()->getSprite(3, 0, 0, 16, 16);
    sf::FloatRect gb = sprite.getLocalBounds();
    sprite.setOrigin(gb.width / 2, gb.height / 2);
    sprite.setPosition(x, y);

    colider.start(x, y, gb.width, gb.height);

    console("Player Created!\n", 2);

}

bool Player::update(float dt)
{

    float vel = 50.f;

    if(Pengo::getInstance()->K_UP)y-=vel*dt;
    if(Pengo::getInstance()->K_DOWN)y+=vel*dt;
    if(Pengo::getInstance()->K_LEFT)x-=vel*dt;
    if(Pengo::getInstance()->K_RIGHT)x+=vel*dt;

    sprite.setPosition(x, y);
    colider.moveCenteredTo(x, y);

    Pengo::getInstance()->window.draw(sprite);

    return true;
}