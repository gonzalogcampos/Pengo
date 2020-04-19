#pragma once
#include <GameObject.h>   

class Pengo : public GameObject
{
    public:
        Pengo(int x, int y);
        ~Pengo();

        void update(float dt);

        void draw();

        int getLifes();

        bool hit();
        
        void setLifes(int l);

    private:
        enum pengoState{S_U,S_D,S_L,S_R,W_U,W_D,W_L,W_R,H_U,H_D,H_L,H_R};
        unsigned int anim_SU, anim_SD, anim_SR, anim_SL, 
                        anim_WU, anim_WD, anim_WL, anim_WR,
                        anim_HU, anim_HD, anim_HL, anim_HR;
        pengoState state;
        float walking_Time = 0.f;
        float hit_Time = 0.f;
        int lifes = 3;
        
};