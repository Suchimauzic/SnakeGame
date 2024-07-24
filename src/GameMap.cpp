#include "GameMap.h"

GameMap::GameMap()
{
    map = new char[this->mapWidth * this->mapHeight + 1];
    map[this->mapWidth + this->mapHeight] = '\0';
    this->initMap();
}

GameMap::~GameMap()
{
    delete[] map;
}

int GameMap::getMapWidth()
{
    return this->mapWidth;
}

int GameMap::getMapHeight()
{
    return this->mapHeight;
}

char GameMap::getWallMap()
{
    return this->MAPWALL;
}

void GameMap::initMap()
{
    for (int i = 0; i < this->mapWidth; i++)
    {
        for (int j = 0; j < this->mapHeight; j++)
        {
            char temp = ' ';

            if (i == 0 || i == this->mapWidth - 1 || j == 0 || j == this->mapHeight - 1)
                temp = this->MAPWALL;
            
            map[i + j * this->mapWidth] = temp;
        }
    }
}

char GameMap::getCharMap(int charNumber)
{
    return this->map[charNumber];
}