// from phattrienphanmem 123--az fixed by me
#include "Map.h"

void GameMap::LoadMap(const char* name) {
    std::ifstream fp(name);
    if (!fp.is_open()) return;

    map.max_x = 0;
    map.max_y = 0;

    std::string line;
    int countrow = 0;
    while (getline(fp, line)) {
        countrow++;
        std::stringstream ss(line);
        int val;
        std::vector<int> row;
        while (ss >> val) {
            row.push_back(val);
            if (val > 0) {
                if (row.size() > map.max_x) map.max_x = row.size();
            }
        }
        map.tile.push_back(row);
        if (countrow == MAX_MAP_Y) break;
    }

    map.max_y = map.tile.size();
    if (map.max_y > MAX_MAP_Y) map.max_y = MAX_MAP_Y;

    fp.close();
}

//void GameMap::LoadTiles(SDL_Renderer* screen) {
    //std :: ifstream fp;
  //  for (int i = 1; i < MAX_TILES; i++) {
    //    std :: string file_img;
      //  file_img = "value/" + std::to_string(i) + ".png";
        // fp.open(file_img);
        // if (!fp.is_open()) continue;
        // fp.close();
        //tile_map[i].LoadImg(file_img, screen); 
    //}
//}

void GameMap::DrawMap(SDL_Renderer* screen) {
    int map_x = map.start_x / TILE_SIZE;
    int map_y = map.start_y / TILE_SIZE;

    for (int i = 0; i < WINDOW_HEIGHT / TILE_SIZE + 2; i++) {
        map_x = map.start_x / TILE_SIZE;
        for (int j = 0; j < WINDOW_WIDTH / TILE_SIZE + 2; j++) {
            if (map_y >= 0 && map_y < map.tile.size() && map_x >= 0 && map_x < map.tile[0].size()) {
                int val = map.tile[map_y][map_x];
                if (val > 0) {
                    tile_map[val].SetRect(j * TILE_SIZE - map.start_x % TILE_SIZE, i * TILE_SIZE - map.start_y % TILE_SIZE);
                    tile_map[val].Render(screen, nullptr);
                }
            }
            map_x++;
        }
        map_y++;
    }
}
