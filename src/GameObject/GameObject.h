#pragma once
/*
Virtual class of all the Game Objects
*/
class GameObject
{
    public:
        GameObject(int x, int y){this->x = x; this->y = y; this->toKill = false;};

        virtual ~GameObject(){};

        virtual void update(float dt) = 0;

        virtual void draw() = 0;

        void kill(){this->toKill = true;}

        bool getKill(){return toKill;};

        void noUpdate(){this->wasUpdate = false;}

        int getX(){return x;}
        int getY(){return y;}
        void setX(int x){this->x = x;}
        void setY(int y){this->y = y;}
        
    protected:
        int x, y;
        bool toKill;
        bool wasUpdate = false;

};