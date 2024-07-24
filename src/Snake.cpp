#include "Snake.h"

Snake::Snake()
{
    this->setAlive();
    this->snakeX = 5;
    this->snakeY = 5;

    this->sizeTail = 2;
    this->xTail.push_back(this->snakeX - 1);
    this->xTail.push_back(this->snakeX - 2);
    this->yTail.push_back(this->snakeY);
    this->yTail.push_back(this->snakeY);
}

char Snake::getSnakeHead()
{
    return this->SNAKEHEAD;
}

char Snake::getSnakeBody()
{
    return this->SNAKEBODY;
}

bool Snake::getIsAlive()
{
    return this->isAlive;
}

void Snake::setAlive()
{
    this->isAlive = true;
}

void Snake::setDie()
{
    this->isAlive = false;
}

Snake::Direction Snake::getDir()
{
    return this->dir;
}

void Snake::setDirection(Snake::Direction dir)
{
    this->dir = dir;
}

int Snake::getSnakeX()
{
    return this->snakeX;
}

int Snake::getSnakeY()
{
    return this->snakeY;
}

void Snake::setSnakeX(bool dir)
{
    this->changeTailPosition();

    if (dir)
        this->snakeX++;
    else
        this->snakeX--;
}

void Snake::setSnakeY(bool dir)
{
    this->changeTailPosition();

    if (dir)
        this->snakeY++;
    else
        this->snakeY--;
}

void Snake::snakeIncreaseTail()
{
    this->sizeTail++;
    this->xTail.push_back(this->xTail[sizeTail - 2]);
    this->yTail.push_back(this->yTail[sizeTail - 2]);
}

void Snake::changeTailPosition()
{
    for (int i = this->sizeTail - 1; i > 0; i--)
    {
        this->xTail[i] = this->xTail[i - 1];
        this->yTail[i] = this->yTail[i - 1];
    }

    this->xTail[0] = this->getSnakeX();
    this->yTail[0] = this->getSnakeY();
}
