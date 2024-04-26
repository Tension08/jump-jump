#include "bullet.h"
BulletObject::BulletObject()
{
    x_val_ = 0;
    y_val_ = 0;
    is_move_ = false;
    bullet_type_ = ROCK;
}

BulletObject::~BulletObject()
{   
    free();
}

void BulletObject::HandleMove(const int& x_border, const int& y_border){
    if(bullet_dir_ == DIR_RIGHT){
        rect.x += x_val_;
        if(rect.x > x_border){
            is_move_ = false;
        }
    }
    else if(bullet_dir_ == DIR_LEFT){
        rect.x -= x_val_;
        if(rect.x < 0 ){
            is_move_ = false;
        }
    }
}

bool BulletObject::LoadImgBullet(SDL_Renderer* des){
    bool ret = false;
    if (bullet_type_ == ROCK){
        ret = LoadImg("value/rock.png", des);
    }
    else if(bullet_type_ == MAGIC){
        ret = LoadImg("value/magic.png", des);
    }
    return ret;
}
