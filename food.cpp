#include "food.h"

Food::Food()
{
    foodImg = newimage();
    getimage(foodImg, "./snake/assets/food.jpg");
}

void Food::setImages()
{
    foodImg = newimage();
    getimage(foodImg, "./snake/assets/food.jpg");
}

void Food::draw()
{
    putimage(food.x, food.y, foodImg);
}

void Food::generateRandomly(vector<Point>& wall_position)
{
    int x = rand() % ((WINDOW_WIDTH - 2 * GRID_SIZE) / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
    int y = rand() % ((WINDOW_HEIGHT - 2 * GRID_SIZE) / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
    for (auto &p : wall_position)
    {
        if (x == p.x && y == p.y)
        {
            generateRandomly(wall_position);
            return;
        }
    }
    food = {x, y};
}

Food::~Food()
{
    delimage(foodImg);
}
