#include "MainWindow.h"

MainWindow::MainWindow()
{
    this->items = new std::string[this->ITEMSCOUNT];
    this->items[0] = "start";
    this->items[1] = "exit";
    this->choice = 0;
}

MainWindow::~MainWindow()
{
    delete[] items;
}

short MainWindow::getChoice()
{
    bool selected = false;

    while (!selected)
    {
        this->draw();
        selected = this->input();
    }

    return this->choice;
}

void MainWindow::draw()
{
    Refresh::refresh(0, 0);
    
    std::cout << "   ____" << std::endl;
    std::cout << " / ____ \\" << std::endl;
    std::cout << "| /    \\ \\" << std::endl;
    std::cout << " \\|     | |" << std::endl;
    std::cout << "  V     / \\" << std::endl;
    std::cout << "        \\_/" << std::endl;

    std::cout << std::endl << " A snake game" << std::endl;

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

bool MainWindow::input()
{
    switch (getch())
    {
        case 'w':
        case 72:
            if (this->choice > 0)
                this->choice--;
            return false;
            break;
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