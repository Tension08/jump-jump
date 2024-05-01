//from phattrienphanmem 123--az fixed by me
#include "MainObject.h"
#include "bullet.h"
MainObject :: MainObject() 
{   
    HP = HP_MAX;
    frame = 0;
    x_pos = 0; 
    y_pos = WINDOW_HEIGHT - 170;
    x_val = 0;
    y_val = 0;
    width_frame = 0;
    height_frame = 0;
    input_type.jump = 0;
    input_type.right = 1;
    input_type.left = 0;
    input_type.down = 0;
    status = -1;
    on_ground = false;
    Uint32 last_bullet_time_ = 0;
}
MainObject :: ~MainObject()
{
    free();
}

bool MainObject :: LoadImg(std :: string path, SDL_Renderer* screen)
{
    bool rect_ = BaseObject :: LoadImg(path, screen);
    if (rect_ == true) 
    {
        width_frame = rect.w/CHAR_FRAMES;
        height_frame = rect.h;
    }

    return rect_;
}

void MainObject :: set_clips()
{
    if (width_frame > 0 && height_frame > 0) 
    {   
        frame_clip[0] = {0 * width_frame,0,width_frame,height_frame};
        frame_clip[1] = {1 * width_frame,0,width_frame,height_frame};
        frame_clip[2] = {2 * width_frame,0,width_frame,height_frame};
        frame_clip[3] = {3 * width_frame,0,width_frame,height_frame};
        frame_clip[4] = {4 * width_frame,0,width_frame,height_frame};
        frame_clip[5] = {5 * width_frame,0,width_frame,height_frame};
        frame_clip[6] = {6 * width_frame,0,width_frame,height_frame};
        frame_clip[7] = {7 * width_frame,0,width_frame,height_frame};
    }
}

void MainObject :: Show (SDL_Renderer* des) 
{   
    ++frame;
    if(frame/8 >=8){
        frame = 0;
    }
    rect.x = x_pos;
    rect.y = y_pos;

    SDL_Rect* current_clip = &frame_clip[frame/8];

    SDL_Rect renderQuad = {rect.x, rect.y, width_frame, height_frame};

    SDL_RenderCopy(des, object, current_clip, &renderQuad);
}

void MainObject :: HandleInputAction(SDL_Event event, SDL_Renderer* screen)
{
    if(event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
            case SDLK_UP:
                status = JUMP;
                input_type.jump = 1;
                break;
             /*case SDLK_m:
                 status = RUN_RIGHT;
                 input_type.right = 1;
                 input_type.left = 0;
                 break;
             case SDLK_LEFT:
                 status = RUN_LEFT;
                 input_type.left = 1;
                 input_type.right = 0;  */
            case SDLK_DOWN:
                input_type.down = 1;
                break;
            default : break;
        }
    }
    else if(event.type == SDL_KEYUP)
    {
          /*switch(event.key.keysym.sym)
          {
            case SDLK_RIGHT:
            {
                input_type.right = 0;
            }
            break;
            case SDLK_LEFT:
            {
                input_type.left = 0;
            }
            break;
        }*/
    }
    else if(event.type == SDL_MOUSEBUTTONDOWN){
        Uint32 current_time = SDL_GetTicks();
        if(event.button.button == SDL_BUTTON_LEFT){
            Uint32 time_since_last_bullet = current_time - last_bullet_time_;
            if (time_since_last_bullet >= 5000)
            {
                BulletObject* p_bullet = new BulletObject();
                p_bullet->set_bullet_type(BulletObject::MAGIC);
                p_bullet->LoadImgBullet(screen);

                if (status == RUN_LEFT) {
                    p_bullet->set_bullet_dir(BulletObject::DIR_LEFT);
                    p_bullet->SetRect(this->rect.x + 10, rect.y + height_frame * 0.25);
                }
                else {
                    p_bullet->set_bullet_dir(BulletObject::DIR_RIGHT);
                    p_bullet->SetRect(this->rect.x + width_frame - 20, rect.y + height_frame * 0.25);
                }
                p_bullet->set_x_val(3);
                p_bullet->set_y_val(3);
                p_bullet->set_is_move(true);

                p_bullet_list_.push_back(p_bullet);

                last_bullet_time_ = current_time;
            }
        }
    }

}

void MainObject::HandleBullet(SDL_Renderer* des){
        for(int i=0; i < p_bullet_list_.size(); i++){
            BulletObject* p_bullet = p_bullet_list_.at(i);
            if(p_bullet != NULL){
                if(p_bullet-> get_is_move() == true){
                    p_bullet->HandleMove(WINDOW_WIDTH, WINDOW_HEIGHT);
                    p_bullet->Render(des);
                }
                else{
                    p_bullet_list_.erase(p_bullet_list_.begin() + i);
                    if(p_bullet != NULL){
                        delete p_bullet;
                        p_bullet = NULL;
                    }
                }
            }
        }
}

void MainObject :: setBlendMode (SDL_BlendMode blending)
{
    SDL_SetTextureBlendMode( object, blending );
}

void MainObject :: DoPlayer(Map& map_data)
{
    x_val  = 0;
    y_val  += 0.8;

    if(y_val >= MAX_FALL_SPEED)
    {
        y_val = MAX_FALL_SPEED;
    }

    if(y_val >= MAX_FALL_SPEED){
            y_val = MAX_FALL_SPEED;
        }

     /*if(input_type.left == 1){
             x_val -= PLAYER_SPEED;
         }*/

          if(input_type.right == 1){
                x_val += PLAYER_SPEED;
                if (x_pos = WINDOW_WIDTH / 3) input_type.right == 0;
          }
        if(input_type.jump == 1)
        {
            if(on_ground ==  true)
            {
                y_val = - PLAYER_JUMP_VAL;
            }
            on_ground = false;
            input_type.jump = 0;
        }

    CheckToMap(map_data);
    //CenterEntityOnMap(map_data);
}

void MainObject :: CheckToMap(Map& map_data)
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
    /*else if (x_pos + width_frame  > map_data.max_x)
    {
        x_pos = map_data.max_x - width_frame - 1;
    }*/
}

 SDL_Rect MainObject::GetRectFrame(){
     SDL_Rect rect_;
     rect_.x = rect.x;
     rect_.y = rect.y;
     rect_.w = width_frame;
     rect_.h = height_frame;
     return rect_;
 }

 void MainObject::RemoveBullet(const int& idx){
    auto size = p_bullet_list_.size();
    if(size > 0 && idx < size){
        BulletObject* p_bullet = p_bullet_list_.at(idx);
        p_bullet_list_.erase(p_bullet_list_.begin() + idx);

        if(p_bullet){
            delete p_bullet;
            p_bullet = NULL;
        }
    }
}
