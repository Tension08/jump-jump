#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "background.h"

int main (int argc, char* args[]) 
{
    if  ((SDL_Init(SDL_INIT_VIDEO)) > 0)
    {
        std :: cout << "Failed SDL_init! SDL_error  : \n" << SDL_GetError() << std:: endl;
    }
    if (!(IMG_Init(IMG_INIT_PNG))) 
    {
        std :: cout << "Failed img_init! SDL_error  : \n" << SDL_GetError() << std :: endl;
    }

    RenderBackground gwindow("jump jump", Window_Width, Window_Height);
    SDL_Texture* background = gwindow.loadTexture("src/background.png");

    bool run = true;

    SDL_Event e;
    
    while (run) 
    {
        while (SDL_PollEvent(&e)) 
        {
            if (e.type == SDL_QUIT) 
            {
                run = false;
            }
        }
        gwindow.clear();
        gwindow.render(background);
        gwindow.display();
    }
    gwindow.cleanUp();
    SDL_Quit();
    return 0;
} 