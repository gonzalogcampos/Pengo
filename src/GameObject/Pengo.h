#pragma once
#include <GameObject.h>

enum State{
    S_U,
    S_D,
    S_L,
    S_R,
    W_U,
    W_D,
    W_L,
    W_R
};
        

class Pengo : public GameObject
{
    private:
        unsigned int anim_SU, anim_SD, anim_SR, anim_SL, anim_WU, anim_WD, anim_WL, anim_WR;
        State state;
        float walking_Time = 0.f;
        
    public:
    Pengo(int x, int y);
    ~Pengo();

    void update(float dt);

    void draw();
};