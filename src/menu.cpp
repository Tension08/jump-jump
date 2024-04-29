#include "CommonFunc.h"

int SDLCommonFunc::showMenu(SDL_Renderer* screen, int& remaindertime_menu)
{
	SDL_RenderClear(screen);
	BaseObject menu_bg;
	menu_bg.LoadImg("value/menu.png", screen);
	menu_bg.Render(screen, NULL);
    SDL_RenderPresent(screen);

	bool menu_running = true;
    int check;

	while (menu_running)
	{
		SDL_Event event;
		remaindertime_menu = SDL_GetTicks() / 1000;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				menu_bg.free();
				menu_running = false;
				check = -1;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
                int mouseX, mouseY;
                SDL_GetMouseState(&mouseX, &mouseY);
				if (mouseX >= 411 && mouseX <= 557 && mouseY >= 225 && mouseY <= 258) 
				{
					menu_running = false;
					check = 1;
					menu_bg.free();
				}

				if (mouseX >= 409 && mouseX <= 558 && mouseY >= 284 && mouseY <= 317)
				{
					menu_running = false;
                    check = 2;
					menu_bg.free();
				}

				if (mouseX >= 410 && mouseX <= 558 && mouseY >= 345 && mouseY <= 379)
				{
					menu_running = false;
					check = 3;
					menu_bg.free();
				}

                if (mouseX >= 452 && mouseX <= 514 && mouseY >= 407 && mouseY <= 467)
				{
					menu_running = false;
					check = 4;
					menu_bg.free();
				}

			}
		}
	}
	return check;
}

