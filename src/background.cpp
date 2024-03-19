#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "background.h"

RenderBackground::RenderBackground(const char* title, int w, int h) : gwindow(NULL), grenderer(NULL) 
{
    gwindow = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN);
    if (gwindow == NULL)
    {
        std :: cout << "Failed to init window ! SDL_Error : \n" << SDL_GetError();
    }
    grenderer  = SDL_CreateRenderer(gwindow, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderBackground :: loadTexture (std :: string path)
{
    SDL_Texture* background = NULL;
    SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
    background = SDL_CreateTextureFromSurface( grenderer, loadedSurface );
    if (background == NULL) 
    {
        std  :: cout << "Failed to load background! SDL_Error: \n" << SDL_GetError();
    }
    return background;
}

void RenderBackground :: cleanUp() 
{
    SDL_DestroyWindow(gwindow);
}

void RenderBackground :: clear() 
{
    SDL_RenderClear(grenderer);
} 

void RenderBackground :: render(SDL_Texture* texture)
{
    SDL_RenderCopy(grenderer, texture, NULL, NULL);
}

void  RenderBackground :: display() 
{
    SDL_RenderPresent(grenderer);
}