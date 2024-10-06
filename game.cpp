#include "game.h"

Game::Game()
{
    menu.showMenu();
    menu.listenMenu();
}

void Game::snakeAction(bool& ifAte, bool& ifSecondAte, int mode[])
{
    if (mode[0] == 1 && mode[1] == 0)
    {
        ifAte = snake.move(wall.getWallPosition(), food.getFood()); 
        food.draw(wall.getWallPosition(), ifAte);
        snake.draw();  
    }
    else
    {
        ifAte = snake.move(wall.getWallPosition(), food.getFood()); 
        ifSecondAte = secondSnake.move(wall.getWallPosition(), food.getFood());
        food.draw(wall.getWallPosition(), ifAte);
        food.draw(wall.getWallPosition(), ifSecondAte);
        snake.draw();   
        secondSnake.draw();
    }
}

void Game::updateRandomWall(bool& ifAte, bool& ifSecondAte, int mode[])
{
    if (mode[0] == 1 && mode[1] == 0)
    {
        if (ifAte)
        {
            wall.generateRandomly(food.getFood());
            ifAte = false;
        }
        return;
    }
    else
    {
        if (ifAte)
        {
            wall.generateRandomly(food.getFood());
            ifAte = false;
        }
        if (ifSecondAte)
        {
            wall.generateRandomly(food.getFood());
            ifSecondAte = false;
        }
    }
}

bool Game::checkGameOver(int mode[])
{
    if (isQuit)
    {
        return false;
    }

    if (mode[0] == 1 && mode[1] == 0)
    {
        if (isRunning && !snake.isGameOver())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (isRunning && !snake.isGameOver() && !secondSnake.isGameOver())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Game::reportScore()
{
    char buffer[100];
    if (mode[0] == 1 && mode[1] == 0)
    {
        sprintf(buffer, "Game Over! Your score: %d", snake.getScore());
    }
    else
    {
        if (snake.isGameOver() || secondSnake.isGameOver())
        {
            sprintf(buffer, "Game Over! first score: %d, second score: %d", score, secondScore);
        }
    }
    MessageBox(NULL, buffer, "Snake Game", MB_OK);
    menu.reset();   
}

void Game::run()
{
    setbkcolor(BLACK);
    bool ifAte, ifSecondAte;
    while (checkGameOver(mode)) 
    {  
        cleardevice();

        if (kbhit()) 
        {  
            char key = getch();  

            if (key == ' ')
            {
                menu.stopMenu();
                menu.listenStopMenu();
                continue;
            }

            snake.changeDirection(key); 
            if (mode[0] == 0 && mode[1] == 1) 
            {
                secondSnake.changeDirection(key); 
            }
        }     

        snakeAction(ifAte, ifSecondAte, mode);

        wall.draw(); 

        snake.printScore();
        if (mode[0] == 0 && mode[1] == 1)
        {
            secondSnake.printScore();
        }

        updateRandomWall(ifAte, ifSecondAte, mode);

        delay_fps(VELOCITY);
    }  

    if (isQuit)
    {
        return;
    }

    reportScore();
}

