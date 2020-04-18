#pragma once
#include "GameObject.h"

class SnoBee : public GameObject
{
    private:
        enum snobeeState{S_U,S_D,S_L,S_R,W_U,W_D,W_L,W_R, STUNNED};
        unsigned int anim_SU, anim_SD, anim_SR, anim_SL, anim_WU, anim_WD, anim_WL, anim_WR, anim_Stunned;
        snobeeState state;
        float walking_Time = 0.f;
        float stunned_Time = 0.f;
    public:
        SnoBee(int x, int y);
        ~SnoBee();

        void update(float dt);

        void draw();

        void stun();
};