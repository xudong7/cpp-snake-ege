#pragma once

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