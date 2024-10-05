#pragma once

#include "menu.h"
#include "snake.h"
#include "wall.h"

class Game
{
    Snake snake;
    Menu menu;
    Wall wall;
public:
    Game();
    void run();
};

