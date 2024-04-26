// from phattrienphanmem 123-az and fixed by me
#include "ThreatsObject.h"

ThreatsObject::ThreatsObject(){
    width_frame = 0;
    height_frame = 0;
    x_val = 0.0;
    y_val = 0.0;
    x_pos = 0.0;
    y_pos = 0.0;
    on_ground = 0;
    frame = 0;
    input_type.left = 0;
    type_move_ = STATIC_THREAT;

}
ThreatsObject::~ThreatsObject(){
    free();
}

bool ThreatsObject::LoadImg(std::string path, SDL_Renderer* screen){
    bool ret = BaseObject::LoadImg(path,screen);
    if(ret){
        width_frame = rect.w/THREAT_FRAME_NUM;
        height_frame = rect.h;
    }
    return ret;
}

SDL_Rect ThreatsObject::GetRectFrame(){
     SDL_Rect rect_;
     rect_.x = rect.x;
     rect_.y = rect.y;
     rect_.w = width_frame;
     rect_.h = height_frame;
     return rect_;
 }

void ThreatsObject::set_clips()
{
    if(width_frame > 0 && height_frame > 0)
    {
        frame_clip[0] = {0,0,width_frame,height_frame};
        frame_clip[1] = {width_frame,0,width_frame,height_frame};
        frame_clip[2] = {2*width_frame,0,width_frame,height_frame};
        frame_clip[3] = {3*width_frame,0,width_frame,height_frame};
    }
}

void ThreatsObject::Show(SDL_Renderer* des){
        rect.x = x_pos ;
        rect.y = y_pos ;
        if(type_move_ != FALL){
            ++frame;
            if(frame/4 >= 4){
                frame = 0;
            }
        SDL_Rect* currentClip = &frame_clip[frame/4];
        SDL_Rect rendQuad = { rect.x, rect.y, width_frame, height_frame};
        SDL_RenderCopy(des, object, currentClip, &rendQuad);
        }
        else
        {
            SDL_RenderCopy(des, object, NULL, &rect);
        }
}

void ThreatsObject::DoPlayer(Map& map_data){
    x_val = 0;
    if(input_type.left == 1){
    x_val -= THREAT_SPEED;
    }  
    CheckToMap(map_data);
}

void ThreatsObject::RemoveBullet(const int& idx){
    int size = bullet_list_.size();
    if(size > 0 && idx < size){
        BulletObject* p_bullet = bullet_list_.at(idx);
        bullet_list_.erase(bullet_list_.begin() + idx);

        if(p_bullet){
            delete p_bullet;
            p_bullet = NULL;
        }
    }
}

void ThreatsObject :: CheckToMap(Map& map_data)
{
    int x1 = x_pos;
    int x2 = x1 + TILE_SIZE;

    int y1 = y_pos;
    int y2 = y1 + TILE_SIZE;

    int height_min  = height_frame < TILE_SIZE ? height_frame : TILE_SIZE;
    x1 = (x_pos + x_val) / TILE_SIZE;
    x2 = (x_pos + x_val + width_frame - 1)/TILE_SIZE;

    y1 = (y_pos)/TILE_SIZE;
    y2 = (y_pos + height_min -1 )/TILE_SIZE;

    if  (x1 >= 0 && x2 < MAX_MAP_X && y1 >=0 && y2 < MAX_MAP_Y )
    {
        if  (x_val  > 0)
        {
            if(map_data.tile[y1][x2] != 0 || map_data.tile[y2][x2] != 0)
            {
                x_pos = x2*TILE_SIZE;
                x_pos -= width_frame +1;
                x_val = 0;
            }
        }
        else if (x_val < 0)
        {
            if (map_data.tile[y1][x1] != 0 || map_data.tile[y2][x1] != 0)
            {
                x_pos  = (x1+1)*TILE_SIZE;
                x_val = 0;
            }
        }
    } 

    int width_min = width_frame < TILE_SIZE ? width_frame : TILE_SIZE;
    x1 = x_pos/TILE_SIZE;
    x2 = (x_pos + width_min)/TILE_SIZE;

    y1 = (y_pos  + y_val)/TILE_SIZE;
    y2 = (y_pos  + y_val + height_frame - 1)/TILE_SIZE;

    if  (x1 >= 0 && x2 < MAX_MAP_X && y1 >=0 && y2 < MAX_MAP_Y )
    {
        if  (y_val  > 0)
        {
            if(map_data.tile[y2][x1] != 0 || map_data.tile[y2][x2] != 0)
            {
                y_pos = y2*TILE_SIZE;
                y_pos -= height_frame +1;
                y_val = 0;
                on_ground  = true;
            }
        }
        else if (y_val < 0)
        {
            if (map_data.tile[y1][x1] != 0 || map_data.tile[y1][x2] != 0)
            {
                y_pos  = (y1+1)*TILE_SIZE;
                y_val = 0;
            }
        }
    }
    x_pos  += x_val;
    y_pos  += y_val;

    if (x_pos  < 0) 
    {
        x_pos = 0;
    } 
    else if (x_pos + width_frame  > map_data.max_x)
    {
        x_pos = map_data.max_x - width_frame - 1;
    }
}

void ThreatsObject::InitBullet(BulletObject* p_bullet, SDL_Renderer* screen){
    if(p_bullet != NULL){
        p_bullet->set_bullet_type(BulletObject::ROCK);
        bool ret = p_bullet-> LoadImgBullet(screen);
        if(ret){
            p_bullet->set_is_move(true);
            p_bullet->set_bullet_dir(BulletObject::DIR_LEFT);
            p_bullet->SetRect(rect.x + 5 , y_pos + 10);
            p_bullet -> set_x_val(5);
            bullet_list_.push_back(p_bullet);
        }  
    }
    SDL_Delay(100);
}

void ThreatsObject::MakeBullet(SDL_Renderer* screen, const int& x_limit, const int& y_limit){
    for(int i = 0; i < bullet_list_.size(); i++){
        BulletObject* p_bullet = bullet_list_.at(i);
        if(p_bullet != NULL){
            
            if(p_bullet->get_is_move()){
              int bullet_distance = rect.x + width_frame - p_bullet->GetRect().x;
                if(bullet_distance < 1280 && bullet_distance > 0){
                    p_bullet ->HandleMove(x_limit, y_limit);
                    p_bullet-> Render(screen);
                } 
                else{
                    p_bullet->set_is_move(false);
                }              
            }
            else{
                p_bullet-> set_is_move(true);
                p_bullet->SetRect(rect.x + 5, rect.y + 10); 
            }
        }
    }
}