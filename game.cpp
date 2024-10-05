#include "game.h"

Wall::Wall()
{
    wallImg = newimage();
    getimage(wallImg, "./snake/assets/wall.jpg");
}

void Wall::draw()
{
    for (int i = 0; i < WINDOW_WIDTH; i += GRID_SIZE)
    {
        putimage(i, 0, wallImg);
        putimage(i, WINDOW_HEIGHT - GRID_SIZE, wallImg);
    }

    for (int i = 0; i < WINDOW_HEIGHT; i += GRID_SIZE)
    {
        putimage(0, i, wallImg);
        putimage(WINDOW_WIDTH - GRID_SIZE, i, wallImg);
    }

    for (auto &p : wall_position)
    {
        putimage(p.x, p.y, wallImg);
    }
}

void Wall::generateRandomly(Point& food)
{
    int x = rand() % ((WINDOW_WIDTH - 2 * GRID_SIZE) / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
    int y = rand() % ((WINDOW_HEIGHT - 2 * GRID_SIZE) / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
    if (x == food.x && y == food.y)
    {
        generateRandomly(food);
        return;
    }
    Point p = {x, y};
    wall_position.push_back(p);
}

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

