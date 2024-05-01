//from phattrienphanmem 123-az
#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <set>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

static SDL_Window* gwindow = NULL;
static SDL_Renderer* gscreen = NULL;
static SDL_Event e;

const int WINDOW_WIDTH = 960;
const int WINDOW_HEIGHT = 480;
const int FRAME_PER_SECOND = 60;

const int CHAR_FRAMES = 8;


#define MAX_TILES 3
#define TILE_SIZE 48
#define MAX_MAP_X 20
#define MAX_MAP_Y 10

class BaseObject 
{
    public: 
        BaseObject();
        ~BaseObject();
    void SetRect(const float& x, const float& y) {rect.x = x; rect.y = y;}
        SDL_Rect GetRect() {return rect;}
        SDL_Texture* GetObject() const {return object;}
        int GetWidth() const {return rect.w;}
        int GetHeight() const {return rect.h;}

        virtual bool LoadImg(std :: string path, SDL_Renderer* screen);
        void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
        void free();
    protected:
        SDL_Texture* object;
        SDL_Rect rect;
};

class TileMat : public BaseObject{
    public:
        TileMat(){;}
        ~TileMat(){;}
};

struct Map 
{
    int start_x;
    int start_y;

    int max_x;
    int max_y;

    //int tile[MAX_MAP_X][MAX_MAP_Y];
    std :: vector<std :: vector<int>> tile;
    //const char* file;  
};

struct Input
{
    int jump;
    //int slash;
    int right;
    int left;
    //int die;
    //int hurt;
    int down;
};

namespace SDLCommonFunc{
    bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
    int showMenu(SDL_Renderer* screen, int& remaindertime_menu);
    void afterPause(SDL_Event& event, SDL_Renderer* screen, int& menuN, bool& run);
    int showCharacterMenu(SDL_Renderer* screen);
    void showInformation(SDL_Renderer* screen);
}
