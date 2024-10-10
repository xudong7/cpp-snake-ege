#pragma once 
#include "menu.h"

class Food
{
    PIMAGE foodImg;
    Point food = {WINDOW_WIDTH/2 + GRID_SIZE, WINDOW_HEIGHT/2 + GRID_SIZE};
public:
    Food();
    ~Food();
    void setImages();
    void draw(vector<Point>& wall_position, Snake& snake, int ifAteFood = 0);
    void generateRandomly(vector<Point>& wall_position, Snake& snake, int ifAteFood);
    Point& getFood() { return food; }
};