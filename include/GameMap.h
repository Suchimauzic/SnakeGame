#pragma once

class GameMap
{
public:
    GameMap();
    ~GameMap();
    int getMapWidth();
    int getMapHeight();
    int getMap();
    char getCharMap(int charNumber);
    char getWallMap();

private:

    // Map size
    int mapWidth = 20;
    int mapHeight = 20;

    // Map chars
    const char MAPWALL = '#';

    // Map
    char* map;

    void initMap();
};