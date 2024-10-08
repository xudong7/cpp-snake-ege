#include "food.h"
#include "menu.h"

Food::Food()
{
    setImages(); 
}

void Food::setImages()
{
    foodImg = newimage();
    getimage(foodImg, "./cpp-snake-ege/assets/china.jpg");
    // getimage(foodImg, "./assets/china.jpg"); // exe file
}

void Food::draw(vector<Point>& wall_position, Snake& snake, int ifAteFood)
{
    generateRandomly(wall_position, snake, ifAteFood);
    putimage(food.x, food.y, foodImg);
}

void Food::generateRandomly(vector<Point>& wall_position, Snake& snake, int ifAteFood)
{
    if (ifAteFood)
    {
        int x = rand() % ((WINDOW_WIDTH - 2 * GRID_SIZE) / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
        int y = rand() % ((WINDOW_HEIGHT - 2 * GRID_SIZE) / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
        for (auto &p : wall_position)
        {
            if (x == p.x && y == p.y)
            {
                generateRandomly(wall_position, snake, ifAteFood);
                return;
            }
        }
        for (auto &p : snake.getBody())
        {
            if (x == p.x && y == p.y)
            {
                generateRandomly(wall_position, snake, ifAteFood);
                return;
            }
        }
        food = {x, y};
    }

}

Food::~Food()
{
    delimage(foodImg);
}
