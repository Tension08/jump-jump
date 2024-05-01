//from phattrienphanmem123 -- az fixed by me
#include "CommonFunc.h"

BaseObject::BaseObject() 
{
    object = NULL;
    rect.x = 0;
    rect.y = 0;
    rect.w = 0;
    rect.h = 0; 
}

BaseObject :: ~BaseObject() 
{
    free();
}

bool BaseObject :: LoadImg (std::string path, SDL_Renderer* screen)
{
    free();
    SDL_Texture* newTexture = NULL;
    SDL_Surface* loadedSurface = IMG_Load(path.c_str());
    if (loadedSurface == NULL) 
    {
        std :: cout << "Failed to load" <<path.c_str() << SDL_GetError() << std :: endl;
    } 
    else
    {
        SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0,255,255));
        newTexture = SDL_CreateTextureFromSurface(screen, loadedSurface);
        if (newTexture == NULL) 
        {
            std :: cout << "Failed to load" << SDL_GetError() << std::endl;
        } 
        else 
        {
            rect.w = loadedSurface->w;
            rect.h = loadedSurface->h;
        }
        SDL_FreeSurface(loadedSurface);
    }

    object = newTexture;
    return object != NULL;
}

void BaseObject :: Render (SDL_Renderer* des, const SDL_Rect* clip)
{
    SDL_Rect renderquad = {rect.x, rect.y, rect.w, rect.h};
    if( clip != NULL )
	{
		renderquad.w = clip->w;
		renderquad.h = clip->h;
	}
    SDL_RenderCopy(des, object, clip, &renderquad);
}

void BaseObject :: free () 
{
    if (object != NULL) 
    {
        SDL_DestroyTexture(object);
        object = NULL;
        rect.w = 0;
        rect.h = 0;
    }
}