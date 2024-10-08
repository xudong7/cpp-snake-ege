#include "shit.h"

Shit::Shit()
{
    shitImg = newimage();
    getimage(shitImg, "./cpp-snake-ege/assets/shit.jpg");
    // getimage(shitImg, "./assets/shit.jpg"); // exe file
}

void Shit::draw()
{
    for (auto &p : shit_position)
    {
        putimage(p.x, p.y, shitImg);
    }
}

void Shit::generateRandomly(Point& food, vector<Point>& wall_position, Snake& snake, SecondSnake& secondSnake)
{
    int x = rand() % ((WINDOW_WIDTH - 2 * GRID_SIZE) / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
    int y = rand() % ((WINDOW_HEIGHT - 2 * GRID_SIZE) / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
    if (x == food.x && y == food.y)
    {
        generateRandomly(food, wall_position, snake, secondSnake);
        return;
    }
    for (auto &p : snake.getBody())
    {
        if (x == p.x && y == p.y)
        {
            generateRandomly(food, wall_position, snake, secondSnake);
            return;
        }
    }
    for (auto &p : secondSnake.getBody())
    {
        if (x == p.x && y == p.y)
        {
            generateRandomly(food, wall_position, snake, secondSnake);
            return;
        }
    }
    Point p = {x, y};
    shit_position.push_back(p);
}