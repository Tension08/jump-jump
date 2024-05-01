#pragma once
#include "CommonFunc.h"

class BulletObject : public BaseObject
{
    public : 
        BulletObject();
        virtual ~BulletObject();

        enum BulletType{
            ROCK = 50,
            MAGIC = 51
        };

        enum DirBullet{
            DIR_RIGHT = 20,
            DIR_LEFT = 21
        };

        void set_x_val(const int& xVal){x_val_ = xVal;}
        void set_y_val(const int& yVal){y_val_ = yVal;}

        int get_x_val()const{return x_val_;}
        int get_y_val()const{return y_val_;}

        int get_x_pos()const{return rect.x;}
        int get_y_pos()const{return rect.y;}

        void set_is_move( const bool& isMove){is_move_ = isMove;}
        bool get_is_move()const {return is_move_;}

        void HandleMove(const int& x_border, const int& y_border);

        void set_bullet_type(const unsigned int& bulletType){bullet_type_ = bulletType;}
        void set_bullet_dir(const unsigned int& bulletDir){bullet_dir_ = bulletDir;}
        
        unsigned int get_bullet_type()const{return bullet_type_;}
        bool LoadImgBullet(SDL_Renderer* des);

    private:
        int x_val_;
        int y_val_;
        bool is_move_;
        unsigned int bullet_type_;
        unsigned int bullet_dir_;
};