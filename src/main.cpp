#include <Game.h>

int main() {

  Game::getInstance()->start();

  Game::getInstance()->run();

  return 0;
}