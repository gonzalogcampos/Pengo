#pragma once
/*
Virtual class of all the Game Objects
*/
class GameObject
{
    public:
        GameObject(int x, int y){this->x = x; this->y = y; this->toKill = false;};

        ~GameObject(){};

        void update(float dt){};

        void kill(){this->toKill = true;}

        bool getKill(){return toKill;};
    private:
        int x, y;
        bool toKill;

};