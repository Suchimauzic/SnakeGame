#pragma once

class Food
{
public:
    Food(int x, int y);

    void changePos(int x, int y);

    int getPosX();
    int getPosY();

    char getFoodChar();

private:
    const char CHARFOOD = 'F';

    int xPos;
    int yPos;
};