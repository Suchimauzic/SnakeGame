#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include "Snake.h"
#include "GameMap.h"
#include "Food.h"
#include "Refresh.h"

class Game
{
public:
    Game();
    ~Game();
    void gameLoop();

private:
    GameMap* map;
    Snake* snake;
    Food* food;
    
    bool isWin;
    unsigned int score;
    const short SCOREADD = 100; 

    int deltaTime;
    const short CHANGETIME = 3;

    void input();
    void draw();
    void logic();
    bool checkWin();
    void genXY(int& x, int& y);
};