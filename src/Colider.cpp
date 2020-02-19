#include <Colider.h>


void Colider::start(float x, float y, float sx, float sy)
{
    this->x = x;
    this->y = y;
    this->sx = sx;
    this->sy = sy;
}

bool Colider::colides(Colider target)
{
    if(x < target.x + target.sx &&
   x + sx > target.x &&
   y < target.y + target.sy &&
   y + sy > target.y)
   {
       return true;
   }

   return false;
}

void Colider::moveCenteredTo(float x, float y)
{
    this->x = x - (sx / 2);
    this->y = y - (sy / 2);
}

void Colider::moveTo(float x, float y)
{
    this->x = x;
    this->y = y;

}