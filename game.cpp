#include "game.h"

Game::Game()
{
    menu.showMenu();
    menu.listenMenu();
}

void Game::run()
{
    setbkcolor(BLACK);
    bool ifAte;
    while (isRunning && !snake.isGameOver()) 
    {  
        if (kbhit()) 
        {  
            char key = getch();  
            snake.changeDirection(key);  
        }  
  
        ifAte = snake.move(wall.getWallPosition());  

        cleardevice();
        snake.draw();    
        wall.draw(); 
        snake.printScore();

        if (ifAte)
        {
            wall.generateRandomly(snake.getFood());
            ifAte = false;
        }

        delay_fps(VELOCITY);
    }  

    if (snake.isGameOver())
    {
        char buffer[100];
        sprintf(buffer, "Game Over!\nYour score: %d", snake.getScore());
        MessageBox(NULL, buffer, "Snake Game", MB_OK);
        menu.reset();
    }
}

