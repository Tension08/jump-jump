//from laptrinhphanmem 123--az and fixed by me
#pragma once
#include "MainObject.h"

class GameMap 
{
public:
    GameMap() { ; }
    ~GameMap() { ; }

    void LoadMap(const char* name);
    void DrawMap(SDL_Renderer* screen);
    Map getMap() const {return map;};
    void SetMap(Map& map_data){
            map = map_data;
        };
private:
    Map map;  
    TileMat tile_map[MAX_TILES];
};