#include <iostream>
#include "MainWindow.h"
#include "EndWindow.h"
#include "Game.h"

int main()
{
    Game* game;
    EndWindow* ew;

    MainWindow* mw = new MainWindow();
    short choice = mw->getChoice();
    delete mw;

    if (choice == 1)
        return 0;
    
    ew = new EndWindow();
    
    while (choice == 0)
    {
        system("cls");
        game = new Game();
        game->gameLoop();
        delete game;

        system("cls");
        choice = ew->getChoice();
    }

    delete ew;

    return 0;
}