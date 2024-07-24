#pragma once

#include <vector>

class Snake
{
public:
    // tail
    std::vector<int> xTail;
    std::vector<int> yTail;

    // snake's direction
    enum Direction { LEFTDIR, TOPDIR, RIGHTDIR, DOWNDIR };
    
    Snake();

    char getSnakeHead();
    char getSnakeBody();

    bool getIsAlive();
    void setAlive();
    void setDie();
    Direction getDir();
    void setDirection(Direction dir);

    int getSnakeX();
    int getSnakeY();
    void setSnakeX(bool dir);
    void setSnakeY(bool dir);

    void snakeIncreaseTail();
    void changeTailPosition();

private:
    // chars
    const char SNAKEHEAD = '@';
    const char SNAKEBODY = 'o';
    
    // states
    bool isAlive;
    Direction dir;

    // position
    int snakeX;
    int snakeY;

    // tail
    int sizeTail;
};