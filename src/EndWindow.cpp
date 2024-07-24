#include "EndWindow.h"

EndWindow::EndWindow()
{
    this->items = new std::string[this->ITEMSCOUNT];
    this->items[0] = "Yes";
    this->items[1] = "No (exit)";
    this->choice = 0;
}

EndWindow::~EndWindow()
{
    delete[] items;
}

short EndWindow::getChoice()
{
    bool selected = false;

    while (!selected)
    {
        this->draw();
        selected = this->input();
    }

    return this->choice;
}

void EndWindow::draw()
{
    Refresh::refresh(0, 0);
    
    std::cout << "Do you want to try again?" << std::endl;

    for (int i = 0; i < this->ITEMSCOUNT; i++)
    {
        std::cout << "  ";
        if (i == this->choice)
            std::cout << this->LEFTARROWS;
        else
            std::cout << "  ";
        
        std::cout << " " << this->items[i] << " ";

        if (i == this->choice)
            std::cout << this->RIGHTARROWS;
        else
            std::cout << "  ";
        
        std::cout << std::endl;
    }
}

bool EndWindow::input()
{
    switch (getch())
    {
        case 'w':
        case 72:
            if (this->choice > 0)
                this->choice--;
            return false;
        case 's':
        case 80:
            if (this->choice < 1)
                    this->choice++;
            return false;
        case 13:        // Enter
            return true;
        default:
            return false;
    }
}