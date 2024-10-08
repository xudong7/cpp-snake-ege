#include "game.h"

Game::Game()
{
    menu.showMenu();
    menu.listenMenu();
}

void Game::snakeAction(bool& ifAte, bool& ifSecondAte)
{
    if (mode[0] == 1 && mode[1] == 0)
    {
        ifAte = snake.move(wall.getWallPosition(), food.getFood(), shit.getShitPosition()); 
        food.draw(wall.getWallPosition(), ifAte);
        snake.draw();  
    }
    else
    {
        ifAte = snake.move(wall.getWallPosition(), food.getFood(), shit.getShitPosition()); 
        ifSecondAte = secondSnake.move(wall.getWallPosition(), food.getFood());
        food.draw(wall.getWallPosition(), ifAte);
        food.draw(wall.getWallPosition(), ifSecondAte);
        snake.draw();   
        secondSnake.draw();
    }
}

void Game::updateRandomWallAndShit(bool& ifAte, bool& ifSecondAte)
{
    if (mode[0] == 1 && mode[1] == 0)
    {
        if (ifAte)
        {
            wall.generateRandomly(food.getFood(), shit.getShitPosition(), snake, secondSnake);
        }
        if (ifAte && (secondScore+score) % 2 == 0)
        {
            shit.generateRandomly(food.getFood(), wall.getWallPosition(), snake, secondSnake);
        }
    }
    else
    {
        if (ifAte)
        {
            wall.generateRandomly(food.getFood(), shit.getShitPosition(), snake, secondSnake);
        }
        if (ifAte && score % 2 == 0)
        {
            shit.generateRandomly(food.getFood(), wall.getWallPosition(), snake, secondSnake);
        }
        if (ifSecondAte)
        {
            wall.generateRandomly(food.getFood(), shit.getShitPosition(), snake, secondSnake);
        }
        if (ifSecondAte && (secondScore+score) % 2 == 0)
        {
            shit.generateRandomly(food.getFood(), wall.getWallPosition(), snake, secondSnake);
        }
    }
    ifAte = false;
    ifSecondAte = false;
}

bool Game::checkGameOver()
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

void Game::twoSnakeCollision()
{
    if (mode[0] == 0 && mode[1] == 1)
    {
        for (auto &p : secondSnake.getBody())
        {
            if (p.x == snake.getHead().x && p.y == snake.getHead().y)
            {
                snake.setGameOver();
                break;
            }
        }

        for (auto &p : snake.getBody())
        {
            if (p.x == secondSnake.getHead().x && p.y == secondSnake.getHead().y)
            {
                secondSnake.setGameOver();
                break;
            }
        }
    }
}

void Game::run()
{
    setbkcolor(BLACK);
    bool ifAte, ifSecondAte;
    wall.initWallDraw();
    while (checkGameOver()) 
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

        if (score == wantScore || secondScore == wantScore)
        {
            menu.showGameWin();
            menu.listenGameWin();
            return;
        }

        snakeAction(ifAte, ifSecondAte);
        twoSnakeCollision();

        wall.draw(); 
        shit.draw();

        snake.printScore();
        if (mode[0] == 0 && mode[1] == 1)
        {
            secondSnake.printScore();
        }
            
        updateRandomWallAndShit(ifAte, ifSecondAte);

        delay_fps(0.5 * (VELOCITY + SECOND_VELOCITY));
    }  

    if (isQuit)
    {
        return;
    }

    // reportScore(); // windows message box

    menu.showGameOver();
    menu.listenGameOver();
}

