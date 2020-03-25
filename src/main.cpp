#include <Game.h>

int main() {

  Game::getInstance()->Start();
  Game::getInstance()->Run();
  Game::getInstance()->Close();  

  return 0;
}