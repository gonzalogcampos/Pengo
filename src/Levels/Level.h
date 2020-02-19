#pragma once
#include <Player.h>

class Level
{
    public:
        virtual void start() = 0;
        virtual bool update(float dt) = 0;
        virtual void close() = 0;

    protected:
        Player player;
};