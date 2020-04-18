#include <PlayState.h>
#include <Map.h>

void PlayState::initState()
{
    type = IGameState::PLAY;
    Map::getInstance()->init();
} 


void PlayState::update(float dt)
{
   Map::getInstance()->update(dt);
   Map::getInstance()->draw();
}


void PlayState::clear(){

}