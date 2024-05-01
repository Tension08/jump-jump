#pragma once
#include "Map.h"

class PlayerPower : public BaseObject{
    public:
        PlayerPower();
        ~PlayerPower();

        void SetNum(const int& HP){
            HP_ = HP;
        }
        int GetNum() const{
            return HP_;
        }
        void Show (SDL_Renderer* screen);
        void Init(SDL_Renderer* screen);
        void setclip();
        void Decrease();
        void InitCrease();

    private:
        int HP_;
        BaseObject HP_bar_;
        SDL_Rect clip_[4];
};