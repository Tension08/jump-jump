#pragma once
#include "Map.h"
#include "CommonFunc.h"

#define MAX_TILES 200

class TileMap : public BaseObject
{
    public :
        TileMap(){;}
        ~TileMap(){;} 
};

class GameMap 
{
    public:
        GameMap() {;}
        ~GameMap() {;}
        void LoadMap (char const* name);
        void LoadTiles (SDL_Renderer* screen);
        void DrawMap (SDL_Renderer* screen);
    private:
        Map map;
        TileMap tile_map[MAX_TILES];    
};