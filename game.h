#pragma once

#include "menu.h"
#include "snake.h"

class Wall
{
    PIMAGE wallImg;
    vector<Point> wall_position;
public:
    Wall();
    void draw();
    void generateRandomly(Point& food);
    vector<Point>& getWallPosition() { return wall_position; }
};

class Game
{
    Snake snake;
    Menu menu;
    Wall wall;
public:
    Game();
    void run();
};

