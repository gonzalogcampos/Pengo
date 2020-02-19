
#include <Level1.h>
#include <SpriteBank.h>
#include <Pengo.h>

void Level1::start()
{
    player.start();
    player.x = 0.f;
    player.y = 0.f;
    background = SpriteBank::getInstance()->getSprite(2, 0, 0, 223, 255);
    background.setOrigin(0, 0);
    background.setPosition(0, 0);

    for(size_t i = 0; i < (sizeof(ices)/sizeof(*ices)); i++)
        for(size_t j = 0; j < (sizeof(ices[i])/sizeof(*ices[i])); j++)
            if((rand() % 100)<20)
                ices[i][j].start(i, j);
}

bool Level1::update(float dt)
{
    bool r = true;

    Pengo::getInstance()->window.draw(background);


    for(size_t i = 0; i < (sizeof(ices)/sizeof(*ices)); i++)
        for(size_t j = 0; j < (sizeof(ices[i])/sizeof(*ices[i])); j++)
            ices[i][j].update(dt);

    r = player.update(dt);



    return r;

}

void Level1::close()
{

}