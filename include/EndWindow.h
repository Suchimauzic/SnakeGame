#pragma once

#include <iostream>
#include <conio.h>
#include "Refresh.h"

class EndWindow
{
public:
    EndWindow();
    ~EndWindow();
    short getChoice();

private:
    short choice;

    const short ITEMSCOUNT = 2;
    std::string* items;
    const std::string LEFTARROWS = ">>";
    const std::string RIGHTARROWS = "<<";

    void draw();
    bool input();
};