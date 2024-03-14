#include <bits/stdc++.h>
#include <SDL2/SDL.h>

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* loadSurface( std::string path);
SDL_Surface* gStretchSurface = NULL;

SDL_Surface* loadSurface( std::string path ) {
    SDL_Surface* optimizedSurface = NULL;
    SDL_Surface* loadedSurface = SDL_LoadBMP( path.c_str());
    if (loadedSurface == NULL) {
        printf(" Failed to load image %s! SDL_Error : %s\n ", path.c_str(), SDL_GetError());
    }
    else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface( loadedSurface, gScreenSurface->format, 0 );
		if( optimizedSurface == NULL )
		{
			printf( "Unable to optimize image %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( loadedSurface );
	}
    return optimizedSurface;
};

bool init () {
    bool success = true;
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf ("SDL2 can't be print %s\n", SDL_GetError());
    }
    else {
        gWindow = SDL_CreateWindow("tester", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gWindow == NULL) {
            printf ("Window can't be print%s\n", SDL_GetError());
            success = false;
        }
        else {
            gScreenSurface = SDL_GetWindowSurface(gWindow);
        }
    }
    return success;
}

bool loadMedia () {
    bool success = true;
    gStretchSurface = loadSurface( "stretch.bmp" );
	if( gStretchSurface == NULL )
	{
		printf( "Failed to load stretching image!\n" );
		success = false;
	}
    
    return success;
}

void close () {
    SDL_FreeSurface(gStretchSurface);
    gStretchSurface = NULL;
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;
    SDL_Quit();
}

void stretch_image() {
    SDL_Rect stretchRect;
	stretchRect.x = 0;
	stretchRect.y = 0;
	stretchRect.w = SCREEN_WIDTH;
	stretchRect.h = SCREEN_HEIGHT;
	SDL_BlitScaled( gStretchSurface, NULL, gScreenSurface, &stretchRect );
}
			
int main (int argc, char* argv[]) {
    if (!init()) {
        printf ("Error\n");
    }
    else {
        if (!loadMedia()) {
            printf ("Error\n");
        } else {
            SDL_Event e;
            bool quit = false;
            while (!quit) {
                while (SDL_PollEvent(&e) != 0) {
                    if (e.type == SDL_QUIT) {
                        quit = true;
                    }
            }
				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
			}
        }
    }
    close();
}