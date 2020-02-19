#pragma once


class Colider
{
    public:
        float sx, sy, x, y;

        void start(float x, float y, float sx, float sy);
        bool colides(Colider target);
        void moveCenteredTo(float x, float y);
        void moveTo(float x, float y);

};