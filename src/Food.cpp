#include "Food.h"

Food::Food(int x, int y)
{
    this->changePos(x, y);
}

void Food::changePos(int x, int y)
{
    this->xPos = x;
    this->yPos = y;
}

int Food::getPosX()
{
    return this->xPos;
}

int Food::getPosY()
{
    return this->yPos;
}

char Food::getFoodChar()
{
    return this->CHARFOOD;
}