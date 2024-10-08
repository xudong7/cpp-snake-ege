#pragma once
#include "game.h"
#include "snake.h"
#include "secondSnake.h"

class Wall
{
    PIMAGE wallImg;
    vector<Point> wall_position;
public:
    Wall();
    void draw();
    void generateRandomly(Point& food, vector<Point>& shit_position, Snake& snake, SecondSnake& secondSnake);
    void initWallDraw();
    vector<Point>& getWallPosition() { return wall_position; }
};