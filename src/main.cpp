#include "Map.h"
#include "ImpTimer.h"
#include "ThreatsObject.h"
#include "showBar.h"
#include "TextObject.h"

TTF_Font* font = NULL;
bool init() 
{
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) 
    {
        std :: cout << "Failed to init window" <<SDL_GetError()<< std :: endl;
        success = false;
    } 
    else
    {
        SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
        gwindow = SDL_CreateWindow("jump jump", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if (gwindow == NULL) 
        {
            std :: cout << "Failed to create window" << SDL_GetError() <<std::endl;
            success = false;
        }
        else 
        {
            gscreen = SDL_CreateRenderer(gwindow,-1,SDL_RENDERER_ACCELERATED);
            if (gscreen == NULL) 
            {
                std :: cout << "Failed to create render" << SDL_GetError() << std::endl;
                success = false;
            }
            else 
            {
                SDL_SetRenderDrawColor(gscreen, 255, 255, 255, 255);
                int imgFlags = IMG_INIT_PNG;
                if (!(IMG_Init(imgFlags) && imgFlags))
                {
                    std :: cout << "Failed to load img" << SDL_GetError() << std :: endl;
                    success = false;
                }

            }
            if (TTF_Init() == -1) success = false;
            else 
            {
                font = TTF_OpenFont("value/Plane_ValMore.ttf", 30);
            }
        }
    }
    return success;
}

BaseObject background;
MainObject character;
GameMap gamemap;

bool LoadBackground () 
{
    bool ret = background.LoadImg("value/background.png", gscreen);
    if (ret == false)
    {
        std :: cout << "Failed to load background\n" << SDL_GetError() << std :: endl;
        return false;
    } 
    return true;   
}

std::vector<ThreatsObject*> MakeThreadList(){
    std::vector<ThreatsObject*> list_threats;
    for(int i=0; i<50; i++){
        ThreatsObject* p_threat = new ThreatsObject();
        ThreatsObject* p_threat = (threats_static + i);
            if(p_threat != NULL){
                p_threat ->LoadImg("value/static.png",gscreen);
                p_threat ->set_clips();
                p_threat ->set_type_move(ThreatsObject::STATIC_THREAT);
                p_threat ->set_x_pos(WINDOW_WIDTH + 120*i);
                p_threat ->set_y_pos(WINDOW_HEIGHT - 98 - p_threat->get_height_frame());

                p_threat -> set_input_left(1);

            list_threats.push_back(p_threat);
         }
    }
    for(int i=0; i < 1; i++){
        ThreatsObject* p_threat = new ThreatsObject();
        if(p_threat != NULL){
            p_threat -> LoadImg("value/attack.png", gscreen);
            p_threat -> set_clips();
            p_threat ->set_x_pos(WINDOW_WIDTH);
            p_threat ->set_y_pos(WINDOW_HEIGHT - 98 - p_threat->get_height_frame());
            p_threat ->set_type_move(ThreatsObject::ATTACK_THREAT);
            p_threat ->set_input_left(0);
            for (int i = 0; i < 100; i++)
            {
            BulletObject* p_bullet = new BulletObject();
            p_threat->InitBullet(p_bullet, gscreen);
            }
            list_threats.push_back(p_threat);
        }
    }

    return list_threats;
}

BaseObject button;
bool LoadButton ()
{
    bool ret = button.LoadImg("value/button.png", gscreen);
    if (ret == false)
    {
        std :: cout << "Failed to load button\n" << SDL_GetError() << std :: endl;
        return false;
    }
    return true;
}

void close() 
{
    background.free();
    SDL_DestroyRenderer(gscreen);
    gscreen = NULL;
    SDL_DestroyWindow(gwindow);
    gwindow = NULL;
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
}

int main (int argc, char* args[]) 
{
    ImpTimer fps_time;
    if (init() == false) return -1;
    if (LoadBackground() == false) return -1;
    if (LoadButton() == false) return -1;

    TextObject mark_game;
    mark_game.SetColor(TextObject::RED_TEXT);

    int offset = 0;// for background

    std::vector<ThreatsObject*> threats_list = MakeThreadList();

    PlayerPower player_power;
    player_power.Init(gscreen);
    player_power.setclip();
    

    gamemap.LoadMap("value/map.txt");

    bool run = false;
    int menuN = 1;

    while (menuN != -1)
    {   
        int remaindertime_menu = 0;
        menuN = SDLCommonFunc::showMenu(gscreen, remaindertime_menu); 
        std :: string character_name = "value/musketer-run.png";
        if (menuN == 1)
        {
            run = true;
            character.LoadImg(character_name, gscreen);
            character.set_clips();
        }
        else if (menuN ==2)
        {  
            character.free();
            int ret = SDLCommonFunc::showCharacterMenu(gscreen);
            if (ret == 1)
            {
                character_name = "value/musketer-run.png";
            }
            else if (ret == 2)
            {
                character_name = "value/enchatre.png";
            }
            else if (ret == 3)
            {
                menuN = 0;
            }
        }
        else if (menuN == 3)
        {
            break;
        }
        
        while (run) 
        {
            while (SDL_PollEvent(&e))
            {
                if (e.type == SDL_QUIT) 
                {
                    run = false;
                }
                character.HandleInputAction(e,gscreen);
                SDLCommonFunc::afterPause(e, gscreen,menuN, run);
            }

            SDL_SetRenderDrawColor(gscreen, 0, 255, 255, 0);
            SDL_RenderClear(gscreen);
            
            //scrooling background
            background.SetRect(offset,0);
            background.Render(gscreen, NULL);
            offset -= 2;
            background.SetRect(offset + background.GetWidth(), 0);
            background.Render(gscreen, NULL);
            if(offset < -background.GetWidth())
            {
            	offset = 0;
            }

            //set pause button
            button.SetRect(WINDOW_WIDTH - 103,0);
            SDL_Rect clip = {305,45,103,36};
            button.Render(gscreen, &clip);  

            Map map_data = gamemap.getMap();

            for(int i=0; i < threats_list.size(); i++){
                ThreatsObject* p_threat = threats_list.at(i);
                if(p_threat != NULL){
                    p_threat -> DoPlayer(map_data);
                    p_threat -> MakeBullet(gscreen, WINDOW_WIDTH, WINDOW_HEIGHT);
                    p_threat -> Show(gscreen);
                    int check = p_threat -> get_x_pos();

                    SDL_Rect rect_player = character.GetRectFrame();
                    bool bCol1 = false;
                    std::vector<BulletObject*> tBullet_list = p_threat->get_bullet_list_();
                    for(int jj = 0; jj < tBullet_list.size(); jj++){
                        BulletObject* pt_bullet = tBullet_list.at(jj);
                        if(pt_bullet !=  NULL){
                            bCol1 = SDLCommonFunc::CheckCollision(pt_bullet->GetRect(), rect_player);
                            if(bCol1){
                                p_threat->RemoveBullet(jj);
                                break;
                            }
                            if (pt_bullet->get_x_pos() <= 0){
                                p_threat->RemoveBullet(jj);
                            }
                        }
                    }
                    SDL_Rect rect_threat = p_threat->GetRectFrame();
                    bool bCol2 = false;
                    bCol2 = SDLCommonFunc::CheckCollision(rect_player, rect_threat);
                    if (bCol2 || bCol1)
                    {
                        if (character_name == "value/musketer-run.png")
                        {
                            player_power.Decrease();
                            p_threat -> free();
                            p_threat = NULL;
                        }
                        else if (character_name == "value/enchatre.png")
                        {
                            player_power.Decrease();
                            player_power.Decrease();
                            p_threat -> free();
                            p_threat = NULL;
                        }
                    }
                    if (check <= 0){
                        p_threat -> free();
                        
                        p_threat = NULL;
                    }
                }
        }
            if (character_name == "value/enchatre.png")
            {
                std::vector<BulletObject*> bullet_arr = character.get_bullet_list();
                for(int r = 0; r < bullet_arr.size(); r++){
                BulletObject* p_bullet = bullet_arr.at(r);
                if(p_bullet != NULL){
                    for(int t= 0; t < threats_list.size(); t++){
                        ThreatsObject* obj_threat = threats_list.at(t);
                        if(obj_threat != NULL){
                            SDL_Rect tRect;
                            tRect.x = obj_threat->GetRect().x;
                            tRect.y = obj_threat->GetRect().y;
                            tRect.w = obj_threat->get_width_frame();
                        tRect.h = obj_threat->get_height_frame();

                        SDL_Rect bRect = p_bullet->GetRect();

                        bool bCol = SDLCommonFunc::CheckCollision(bRect, tRect);

                        if(bCol){
                            character.RemoveBullet(r);
                            obj_threat->free();
                            threats_list.erase(threats_list.begin() + t);
                        }
                    }
                }
            }
        }

                character.HandleBullet(gscreen);
            }
            character.DoPlayer(map_data);
            character.Show(gscreen);

            player_power.Show(gscreen);
            int finalcheck = player_power.GetNum();

            std::string str_mark = "Far: ";
            Uint32 time_val = SDL_GetTicks()/1000;
            str_mark += std::to_string((time_val - remaindertime_menu) * PLAYER_SPEED);
            mark_game.SetText(str_mark);
            mark_game.LoadFromRenderText(font, gscreen);
            mark_game.RenderText(gscreen, WINDOW_WIDTH/2,0);
            
            gamemap.SetMap(map_data);
            gamemap.DrawMap(gscreen);
            SDL_RenderPresent(gscreen);

            int real_imp_time = fps_time.get_ticks();
            int time_one_frame = 1000/FRAME_PER_SECOND; // tinh theo mili giay

            if(real_imp_time < time_one_frame){
                int delay_time = time_one_frame - real_imp_time;
                if(delay_time >= 0){
                    SDL_Delay(delay_time);
                }
            }
            if (finalcheck > 4)
            {
                character.free();
                TextObject text_game_over;
                text_game_over.SetText("GAME OVER");
                text_game_over.SetColor(TextObject::WHITE_TEXT);
                text_game_over.LoadFromRenderText(font, gscreen);
                text_game_over.RenderText(gscreen, WINDOW_WIDTH/2 - 100, WINDOW_HEIGHT/2 - 50);
                mark_game.RenderText(gscreen, WINDOW_WIDTH/2, WINDOW_HEIGHT/2);
                SDL_RenderPresent(gscreen);
                SDL_Delay(3000);
                run = false;
                menuN = 0;
            }
        } 
        for(int i=0; i< threats_list.size(); i++){
            ThreatsObject* p_threat = threats_list.at(i);
            if(p_threat != NULL){
                p_threat->free();
                delete p_threat;
                p_threat = NULL;
            }
        }
        threats_list.clear();  
    }
        close();
        return 0;
    } 
