//from phatphanmem123-az --- fixed by me
#pragma once 
#include "CommonFunc.h"
#include "bullet.h"

#define GRAVITY_SPEED 0.8f
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 4
#define PLAYER_JUMP_VAL 15
#define HP_MAX 3

class MainObject : public BaseObject
{
    public : 
        MainObject();
        ~MainObject();

        enum ACTION
        {
            JUMP = 1,
            RUN_RIGHT = 2,
            RUN_LEFT  = 3,
            DOWN = 4
        };

        virtual bool LoadImg(std :: string path, SDL_Renderer* screen);
        void Show(SDL_Renderer * des);
        void HandleInputAction(SDL_Event event, SDL_Renderer* screen);
        void set_clips();  
        void setBlendMode(SDL_BlendMode blending);
        void DoPlayer(Map& map_data);
        void CheckToMap(Map& map_data);
       
        void set_bullet_list(std::vector<BulletObject*>bullet_list){p_bullet_list_ = bullet_list;}
        std::vector<BulletObject*> get_bullet_list() const {return p_bullet_list_;}
        void HandleBullet(SDL_Renderer* des);
        void RemoveBullet(const int& idx);

        SDL_Rect GetRectFrame();
    private :
        float x_val;
        float y_val;

        float x_pos;
        float y_pos;

        int width_frame; 
        int height_frame;

        SDL_Rect frame_clip[CHAR_FRAMES];
        Input input_type;
        int frame;

        int status;
        bool on_ground;

        int HP;

        std::vector<BulletObject*> p_bullet_list_;

        Uint32 last_bullet_time_;
};