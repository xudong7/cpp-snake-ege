#pragma once
#include "game.h"
#include "snake.h"
#include "secondSnake.h"

class Shit
{
    PIMAGE shitImg;
    vector<Point> shit_position;
public:
    Shit();
    void draw();
    void generateRandomly(Point& shit, vector<Point>& wall_position, Snake& snake, SecondSnake& secondSnake);
    vector<Point>& getShitPosition() { return shit_position; }
};