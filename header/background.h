#pragma once
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int Window_Width = 960;
const int Window_Height = 540;

class RenderBackground {
    public:
        RenderBackground(const char* title, int w, int h);
        SDL_Texture* loadTexture(std :: string path);
        void cleanUp();
        void render(SDL_Texture* texture);
        void display();
        void clear();
    private:
        SDL_Window* gwindow;
        SDL_Renderer* grenderer;
};
