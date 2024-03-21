#pragma once

#include <bits/stdc++.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

static SDL_Window* gwindow = NULL;
static SDL_Renderer* gscreen = NULL;
static SDL_Event e;

const int WINDOW_WIDTH = 960;
const int WINDOW_HEIGHT = 480;


#define TILE_SIZE 48
#define MAP_MAX_X 20
#define MAP_MAX_Y 10

class BaseObject 
{
    public: 
        BaseObject();
        ~BaseObject();
        void SetRect(const int& x, const int& y) {rect.x = x, rect.y = y;}
        SDL_Rect GetRect() {return rect;}
        SDL_Texture* GetObject() const {return object;}

        bool LoadImg(std :: string path, SDL_Renderer* screen);
        void Render(SDL_Renderer* des, const SDL_Rect* clip = NULL);
        void free();
    protected:
        SDL_Texture* object;
        SDL_Rect rect;
};

typedef struct Map  
{
    int start_x;
    int start_y;

    int max_x;
    int max_y;

    int tile[MAP_MAX_Y][MAP_MAX_X];
    char const* file;
} map;
