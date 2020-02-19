#include <Pengo.h>

int main() {

  Pengo::getInstance()->Start();
  Pengo::getInstance()->Run();
  Pengo::getInstance()->Close();  

  return 0;
}