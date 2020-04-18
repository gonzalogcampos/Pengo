#pragma once

class GameObject;
class Pengo;
class Ice;
class SnoBee;

const int MAP_W = 13;
const int MAP_H = 15;

class Map
{
    private:
        GameObject* map[MAP_W][MAP_H];
        Pengo* pengo;
        Map();
        ~Map();

        int snoBeesCount = 0;
        int level = 0;
        int score = 0;
        unsigned int spriteBack, spritePengo, spriteLife, spriteLoadingB, spriteLoading, spriteLevel, spriteScore;
        unsigned int spriteNums[10];
        bool modoDios = false;
        bool diamantesAlineados = false;
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
        Ice* createEgg(int x, int y);
        Ice* createDiamond(int x, int y);
        SnoBee* createSnobee(int x, int y);
        void update(float dt);
        bool pengoMoving(GameObject* pengo, int dir);
        void pengoHits(int x, int y, int dir);
        bool iceMoving(GameObject* ice, int dir);
        bool snobeeMoving(GameObject* snobee, int dir);
        void loadNextLevel();
        void loadLevel1();
        void loadLevel2();
        void loadLevelRandom();
        bool hitPengo();
        void events();
        void breakEgg();
        void eggBreaks();
        void testDiamonds(int x, int y);
        void stunAll();
        void stunOnMargin();
};