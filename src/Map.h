#pragma once

class GameObject;
class Pengo;
class Ice;
class SnoBee;

const unsigned int MAP_W = 14;
const unsigned int MAP_H = 16;

class Map
{
    private:
        GameObject* map[MAP_W][MAP_H];
        Pengo* pengo;
        Map();
        ~Map();


        unsigned int spriteBack;
    
    public:
        /*
        Singleton
        */
        static Map* getInstance()
        {
            static Map only_instance;
            return &only_instance;
        }


        void init();
        void clear();
        GameObject* getGameobject(int x, int y);
        Pengo* getPengo();
        void draw();
        bool put(GameObject* gameObject, int x, int y);
        bool push(int x, int y);
        bool getPosition(GameObject* gameObject, int &x, int &y);
        Pengo* createPengo(int x, int y);
        Ice* createIce(int x, int y);
        SnoBee* createSnobee(int x, int y);
        void update(float dt);
        bool moveUp(GameObject* gameobject);
        bool moveDown(GameObject* gameobject);
        bool moveLeft(GameObject* gameobject);
        bool moveRight(GameObject* gameobject);



};