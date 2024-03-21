#include "CommonFunc.h"
#include "Map.h"

void GameMap :: LoadMap(char const* name)
{
    FILE* fp = NULL;
    fp = fopen(name, "rb");
    if (fp == NULL) return;

    map.max_x = 0;
    map.max_y = 0;

    for (int i = 0; i < MAP_MAX_Y; i++) {
        for (int j = 0; j < MAP_MAX_X; j++) {
            fscanf(fp, "%d", &map.tile[i][j]);
            int val = map.tile[i][j];
            if (val > 0) {
                if (j > map.max_x) {
                    map.max_x = j;
                }
                if (i > map.max_y) {
                    map.max_y = i;
                }
            }
        }
    }
    map.max_x  = (map.max_x + 1) * TILE_SIZE;
    map.max_y = (map.max_y + 1) * TILE_SIZE;

    map.max_x  = 0;
    map.max_y  = 0;
    map.file = name;
    fclose(fp);
}

void  GameMap :: LoadTiles(SDL_Renderer* screen)
{
    char file_img[MAX_TILES];
    FILE* fp  = NULL;
    for (int i = 0; i < MAX_TILES; i++) {
        sprintf(file_img, "value/%d.png", i);

        fp = fopen(file_img, "rb");
        if (fp == NULL) continue;
        fclose(fp);
        tile_map[i].LoadImg(file_img, screen); 
    }
}

void  GameMap :: DrawMap(SDL_Renderer* screen) 
{
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0, map_x, map_y;

    map_x  = map.start_x /TILE_SIZE;
    map_y  = map.start_y /TILE_SIZE;

    x1 = (map.start_x  % TILE_SIZE)* (-1);
    x2 = x1 + WINDOW_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);
    y1 = (map.start_y  % TILE_SIZE)* (-1);
    y2 = y1 + WINDOW_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);

    for (int i = y1; i < y2; i++) {
        for  (int j = x1; j < x2; j++) {
            int val = map.tile[map_y][map_x];
            if (val > 0) {
                tile_map[val].SetRect(j,i);
                tile_map[val].Render(screen);
            }
            map_x++;
        }
        map_y++;
    }
}