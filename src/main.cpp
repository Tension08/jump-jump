#include "CommonFunc.h"
#include "Map.h"

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
        }
    }
    return success;
}

BaseObject background;
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

void close() 
{
    background.free();
    SDL_DestroyRenderer(gscreen);
    gscreen = NULL;
    SDL_DestroyWindow(gwindow);
    gwindow = NULL;
    IMG_Quit();
    SDL_Quit();
}

int main (int argc, char* args[]) 
{
    if (init() == false) return -1;
    // if (LoadBackground() == false) return -1;

    // GameMap game_map;
    // game_map.LoadMap("value/map.txt");
    // game_map.LoadTiles(gscreen);

    bool run = false;
    while (!run) 
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT) 
            {
                run = true;
            }
        }
        SDL_SetRenderDrawColor(gscreen, 255, 255, 255, 255);
        SDL_RenderClear(gscreen);

        // background.Render(gscreen, NULL);
        // game_map.DrawMap(gscreen);

        SDL_RenderPresent(gscreen);
    }   
    close();
    return 0;
} 