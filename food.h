#pragma once 
#include "menu.h"
#include "snake.h"

class Food
{
    PIMAGE foodImg;
    Point food;
public:
    Food();
    void setImages();
    void draw();
    void generateRandomly(vector<Point>& wall_position);
    Point& getFood() { return food; }
};