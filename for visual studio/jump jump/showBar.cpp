#include "showBar.h"

PlayerPower::PlayerPower(){
    HP_ = 0;
}
PlayerPower::~PlayerPower(){}

void PlayerPower :: setclip()
{
    int width = HP_bar_.GetWidth();
    int height = HP_bar_.GetHeight()/4;
    clip_[0] = {0,0*height,width,height};
    clip_[1] = {0,1*height,width,height};
    clip_[2] = {0,2*height,width,height};
    clip_[3] = {0,3*height,width,height};
}

void PlayerPower::Init(SDL_Renderer* screen){
    HP_bar_.LoadImg("value/HP.png", screen);
}

void PlayerPower::Show(SDL_Renderer* screen){
    HP_bar_.SetRect(0,0);
    HP_bar_.Render(screen, &clip_[HP_]);
    HP_bar_.SetRect(HP_bar_.GetRect().x + 60, HP_bar_.GetRect().y);
}

void PlayerPower::Decrease(){
    HP_++;
}

void PlayerPower::InitCrease(){
    HP_--;
}