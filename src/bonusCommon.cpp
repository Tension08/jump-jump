#include "CommonFunc.h"

bool SDLCommonFunc::CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2){
  int left_a = object1.x;
  int right_a = object1.x + object1.w;
  int top_a = object1.y;
  int bottom_a = object1.y + object1.h;
 
  int left_b = object2.x;
  int right_b = object2.x + object2.w;
  int top_b = object2.y;
  int bottom_b = object2.y + object2.h;
 
  if (left_a > left_b && left_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }
 
  if (left_a > left_b && left_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }
 
  if (right_a > left_b && right_a < right_b)
  {
    if (top_a > top_b && top_a < bottom_b)
    {
      return true;
    }
  }
 
  if (right_a > left_b && right_a < right_b)
  {
    if (bottom_a > top_b && bottom_a < bottom_b)
    {
      return true;
    }
  }
  
  if (left_b > left_a && left_b < right_a)
  {
    if (top_b > top_a && top_b < bottom_a)
    {
      return true;
    }
  }
 
  if (left_b > left_a && left_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }
 
  if (right_b > left_a && right_b < right_a)
  {
    if (top_b > top_a && top_b < bottom_a)
    {
      return true;
    }
  }
 
  if (right_b > left_a && right_b < right_a)
  {
    if (bottom_b > top_a && bottom_b < bottom_a)
    {
      return true;
    }
  }
 
  if (top_a == top_b && right_a == right_b && bottom_a == bottom_b)
  {
    return true;
  }
 
  return false;
};

BaseObject afterpause;
void SDLCommonFunc::afterPause(SDL_Event& event, SDL_Renderer* screen, int& menuN, bool& run)
{
  if (event.type == SDL_MOUSEBUTTONDOWN)
  {
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX >= WINDOW_WIDTH - 103 && mouseX <= WINDOW_WIDTH && mouseY >= 0 && mouseY <= 36)
    { 
      afterpause.LoadImg("value/afterpause.png", screen);
      afterpause.Render(screen, NULL);
      bool is_quit = false;
      SDL_RenderPresent(screen);
      while (!is_quit)
      {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
          if (e.type == SDL_MOUSEBUTTONDOWN)
          {
            int x = e.button.x;
            int y = e.button.y;
            if (x >= 417 && x <= 504 && y >= 200 && y <= 236)
            {
              is_quit = true;
            }
            if (x >= 410 && x <= 505 && y >= 145 && y <= 178)
            {
              menuN = 0;
              is_quit = true;
              afterpause.free();
              run = false;
            }
          }
        }
      }
      if (!is_quit)
      {
        afterpause.free();
      }
    }
  }
}

BaseObject choose;
int SDLCommonFunc::showCharacterMenu(SDL_Renderer* screen)
{
  choose.LoadImg("value/choose.png", screen);
  choose.Render(screen, NULL);

  int check = 0;

  SDL_RenderPresent(screen);
  bool ret = true;
  SDL_Event e;
  while (ret)
  {
    while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
      {
        ret = false;
        break;
      }
      if (e.type == SDL_KEYDOWN)
      {
        switch (e.key.keysym.sym)
        {
          case SDLK_1:
          {
            check = 1;
            ret = false;
            break;

          }
          case SDLK_2:
          {
            check =  2;
            ret = false;
            break;
          }
        }
      }
      if (e.type == SDL_MOUSEBUTTONDOWN)
      {
        int x,y;
        SDL_GetMouseState(&x, &y);
        if(x >= 420 && x <= 513 && y >=80 && y <= 118)
        {
          ret = false;
          check = 3;
        }
      }
    }
  }
  if (!ret)
  {
    choose.free();
  }
  return check;
}

void SDLCommonFunc::showInformation(SDL_Renderer* screen)
{
    BaseObject info;
    info.LoadImg("value/information.png", screen);
    info.Render(screen, NULL);
    SDL_RenderPresent(screen);
    bool ret = true;
    SDL_Event e;
    while (ret)
    {
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                ret = false;
                break;
            }
            if (e.type == SDL_KEYDOWN)
            {
                ret = false;
                break;
            }
        }
    }
    if (!ret)
    {
        info.free();
    }
}