#pragma once

#include "menu.h"
#include "snake.h"
#include "wall.h"
#include "food.h"
#include "secondSnake.h"

class Game
{
    Snake snake;
    SecondSnake secondSnake;
    Menu menu;
    Wall wall;
    Food food;
public:
    Game();
    void run();
    void snakeAction(bool& ifAte, bool& ifSecondAte, int mode[]);
    void updateRandomWall(bool& ifAte, bool& ifSecondAte, int mode[]);
    bool checkGameOver(int mode[]);   
    void reportScore();
};

