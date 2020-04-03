#pragma once
#include <GameObject.h>   

class Pengo : public GameObject
{
    public:
        Pengo(int x, int y);
        ~Pengo();

        void update(float dt);

        void draw();
    
    private:
        enum pengoState{S_U,S_D,S_L,S_R,W_U,W_D,W_L,W_R};
        unsigned int anim_SU, anim_SD, anim_SR, anim_SL, anim_WU, anim_WD, anim_WL, anim_WR;
        pengoState state;
        float walking_Time = 0.f;
        
};