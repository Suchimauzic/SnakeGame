#include "Game.h"

Game::Game()
{
    srand(time(NULL));

    snake = new Snake();
    map = new GameMap();

    // For random position
    int randX;
    int randY;

    genXY(randX, randY);
    food = new Food(randX, randY);

    // Starting data
    isWin = false;
    score = 0;
    deltaTime = 120;
}

Game::~Game()
{
    delete snake;
    delete map;
    delete food;
}

void Game::gameLoop()
{
    while (snake->getIsAlive() && !isWin)
    {
        this->draw();
        this->input();
        this->logic();
        Sleep(deltaTime);
    }

    if (isWin)
        std::cout << "You're win!";
    else
        std::cout << "Game Over!";

    std::cout << std::endl << std::endl;
    system("pause");
}

void Game::draw()
{
    Refresh::refresh(0, 0);

    char temp = ' ';    // pixel
    for (int i = 0; i < map->getMapWidth(); i++)
    {
        for (int j = 0; j < map->getMapHeight(); j++)
        {
            // get map's char
            temp = map->getCharMap(i + j * map->getMapWidth());

            if (j == snake->getSnakeX() && i == snake->getSnakeY())     // Snake head position
            {
                temp = snake->getSnakeHead();
            }  
            else if (j == food->getPosX() && i == food->getPosY())      // Food position
            {
                temp = food->getFoodChar();
            }
            else
            {
                for (int k = 0; k < snake->xTail.size(); k++)
                {
                    if (snake->xTail[k] == j)
                    {
                        if (snake->yTail[k] == i)
                        {
                            temp = snake->getSnakeBody();
                            k = snake->xTail.size();
                        }
                    }
                }
            }
            
            std::cout << temp;
        }

        std::cout << std::endl;
    }

    std::cout << std::endl <<std::endl;
    
    std::cout << "Score: " << score << std::endl;
}

void Game::input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
            case 'w':
            //case 'ц':
            case 72:        // Key UP
                if (snake->getDir() != Snake::DOWNDIR)
                    snake->setDirection(Snake::TOPDIR);
                break;
            
            case 's':
            //case 'ы':
            case 80:        // Key DOWN
                if (snake->getDir() != Snake::TOPDIR)
                    snake->setDirection(Snake::DOWNDIR);
                break;
            
            case 'a':
            //case 'ф':
            case 75:        // Key LEFT
                if (snake->getDir() != Snake::RIGHTDIR)
                    snake->setDirection(Snake::LEFTDIR);
                break;
            
            case 'd':
            //case 'в':
            case 77:        // Key RIGHT
                if (snake->getDir() != Snake::LEFTDIR)
                    snake->setDirection(Snake::RIGHTDIR);
                break;
        }
    }
}

void Game::logic()
{
    // Snake move
    switch (snake->getDir())
    {
        snake->changeTailPosition();

        case Snake::LEFTDIR:
            snake->setSnakeX(0);
            break;
        
        case Snake::RIGHTDIR:
            snake->setSnakeX(1);
            break;
        
        case Snake::TOPDIR:
            snake->setSnakeY(0);
            break;
        
        case Snake::DOWNDIR:
            snake->setSnakeY(1);
            break;
    };

    // Collisions
    if (map->getCharMap(snake->getSnakeX() + snake->getSnakeY() * map->getMapWidth()) == map->getWallMap())
    {
        snake->setDie();
    }
    else if (snake->getSnakeX() == food->getPosX() && snake->getSnakeY() == food->getPosY())
    {
        snake->snakeIncreaseTail();
        this->score += this->SCOREADD;

        if (this->deltaTime > 70)
            this->deltaTime -= this->CHANGETIME;
        
        this->isWin = checkWin();
        if (!isWin)
        {
            int randX, randY;
            this->genXY(randX, randY);
            food->changePos(randX, randY);
        }
    }
    else
    {
        for (int k = 0; k < snake->xTail.size(); k++)
        {
            if (snake->xTail[k] == snake->getSnakeX() && snake->yTail[k] == snake->getSnakeY())
                snake->setDie();
        }
    }
}

bool Game::checkWin()           // Check end of game
{
    bool check = true;

    for (int i = 0; i < map->getMapWidth() * map->getMapHeight(); i++)
    {
        if (map->getCharMap(i) == ' ')
        {
            check = false;
            i = map->getMapWidth() * map->getMapHeight();
        }
    }

    return check;
}

void Game::genXY(int& x, int& y)        // generate x and y for food
{
    bool isEmpty = false;

    while (!isEmpty)
    {
        x = rand() % (map->getMapHeight() - 1) + 1;
        y = rand() % (map->getMapWidth() - 1) + 1;

        if (map->getCharMap(x + y * map->getMapWidth()) != ' ')
            continue;
            
        
        if (snake->getSnakeX() == x && snake->getSnakeY() == y)
            continue;

        for (int k = 0; k < snake->xTail.size(); k++)
        {
            if (snake->xTail[k] == snake->getSnakeX() && snake->yTail[k] == snake->getSnakeY())
                continue;
        }

        isEmpty = true;
    }
}