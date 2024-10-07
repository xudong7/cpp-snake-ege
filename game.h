#pragma once

#include "menu.h"
#include "snake.h"
#include "wall.h"
#include "food.h"
#include "secondSnake.h"
#include "shit.h"

class Game
{
    Snake snake;
    SecondSnake secondSnake;
    Menu menu;
    Wall wall;
    Food food;
    Shit shit;
public:
    Game();
    void run();
    void snakeAction(bool& ifAte, bool& ifSecondAte, bool& ifAteShit);
    void updateRandomWall(bool& ifAte, bool& ifSecondAte);
    bool checkGameOver();   
    void reportScore();
    void twoSnakeCollision();
};

