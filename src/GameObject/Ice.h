#pragma once
#include <GameObject.h>


class Ice : public GameObject
{
    private:
        enum iceState{EGGVIEW, STATIC, UP, DOWN, LEFT, RIGHT, DYING, BREAKING};
        iceState state = STATIC;
        float state_Time = 0.f;
        float  state_Duration = 1.f;
        unsigned int sprite;
        unsigned int dyingAnimation;
        unsigned int eggViewAnimation;
        unsigned int eggBreaking;
        bool hasToDie = false;
        bool egg = false;
        bool diamond = false;
        bool brokenEgg = false;
    public:  
        Ice(int x, int y);

        ~Ice();

        void update(float dt);

        void draw();

        void hits(int dir);

        void dies();

        bool getHasToDie();

        void setEgg();
        bool isEgg();
        bool breakEgg();
        bool isBroken();

        void setDiamond();
        bool isDiamond();
        void findAlignDiamonds();
        void align();
};