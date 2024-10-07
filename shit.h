#pragma once 
#include "menu.h"

class Shit
{
    PIMAGE shitImg;
    Point shit = {WINDOW_WIDTH - 4 * GRID_SIZE, WINDOW_HEIGHT/6 + 4 * GRID_SIZE};
public:
    Shit();
    ~Shit();
    void setImages();
    void draw(vector<Point>& wall_position, int ifAteShit = 0);
    void generateRandomly(vector<Point>& wall_position, int ifAteShit);
    Point& getShit() { return shit; }
};