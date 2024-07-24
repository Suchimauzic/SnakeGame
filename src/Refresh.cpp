#include "Refresh.h"

void Refresh::refresh(int x, int y)      // refresh frame
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}