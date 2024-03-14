#include <bits/stdc++.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Texture* gTexture = NULL;
SDL_Window* gWindow = NULL;
SDL_Renderer* gRenderer = NULL;
SDL_Texture* loadTexture (std:: string path);

bool init() {
    bool success = true;
    gWindow = SDL_CreateWindow("tester", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        printf("Unable to load window", SDL_GetError());
        success = false;
    }
    else {
        gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
        if (gRenderer == NULL) {
            printf("Unable to create render", SDL_GetError);
            success = true;
        }
        else {
            SDL_SetRenderDrawColor(gRenderer, 0 , 0 , 0 ,0);
            int imgFlags = 
        }
    }
}