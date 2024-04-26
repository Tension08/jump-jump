// from phattrienphanmem 123--az fixed by me
#include "Map.h"

void GameMap::LoadMap(const char* name) {
    std::ifstream fp(name);
    if (!fp.is_open()) return;

    map.max_x = 0;
    map.max_y = 0;

    std :: string line;
    int countrow = 0;
    while(getline(fp,line))
    {   
        countrow++;
        std :: stringstream ss(line);
        int val;
        std :: vector<int> row;
        while(ss >> val)
        {
            row.push_back(val);
            if(val > 0)
            {
                if (row.size() > map.max_x) map.max_x = row.size();
                if (countrow > map.max_y) map.max_y = countrow;
            }
        }
        map.tile.push_back(row);
        row.clear();
        if(countrow == MAX_MAP_Y) break;
    }
    map.tile[countrow].pop_back();

    map.max_x = (map.max_x + 1) * TILE_SIZE;
    map.max_y = (map.max_y + 1) * TILE_SIZE;

    map.start_x = 0;
    map.start_y = 0;

    //map.file = name;
    fp.close();
}

void GameMap::LoadTiles(SDL_Renderer* screen) {
    //std :: ifstream fp;
    for (int i = 1; i < MAX_TILES; i++) {
        std :: string file_img;
        file_img = "value/" + std::to_string(i) + ".png";
        // fp.open(file_img);
        // if (!fp.is_open()) continue;
        // fp.close();
        tile_map[i].LoadImg(file_img, screen); 
    }
}

void  GameMap :: DrawMap(SDL_Renderer* screen) 
{
    int x1 = 0, x2 = 0, y1 = 0, y2 = 0;
    int map_x = 0, map_y = 0;

    map_x  = map.start_x /TILE_SIZE;
    map_y  = map.start_y /TILE_SIZE;

    x1 = (map.start_x  % TILE_SIZE)* -1;
    x2 = x1 + WINDOW_WIDTH + (x1 == 0 ? 0 : TILE_SIZE);
    y1 = (map.start_y  % TILE_SIZE)* -1;
    y2 = y1 + WINDOW_HEIGHT + (y1 == 0 ? 0 : TILE_SIZE);

    for (int i = y1; i <= y2; i+= TILE_SIZE) {
        map_x = map.start_x/TILE_SIZE;
        for(int j = x1; j <= x2; j+= TILE_SIZE) {
            if (map_y >= 0 && map_y < map.tile.size() && map_x >= 0 && map_x < map.tile[0].size()){
            int val = map.tile[map_y][map_x];
            if (val > 0) {
                tile_map[val].SetRect(j,i);
                tile_map[val].Render(screen, nullptr);
            }
            }
            map_x++;
        }
        map_y++;
    }
}
