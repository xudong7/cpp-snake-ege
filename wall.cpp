#include "wall.h"

Wall::Wall()
{
    wallImg = newimage();
    getimage(wallImg, "./cpp-snake-ege/assets/wall.jpg");
    // getimage(wallImg, "./assets/wall.jpg"); // exe file
}

void Wall::initWallDraw()
{
    if (wallType[0] == 1)
    {
        
    }
    else if (wallType[1] == 1)
    {
        for (int i = GRID_SIZE; i < WINDOW_WIDTH - GRID_SIZE; i += GRID_SIZE)
        {
            wall_position.push_back({i, 2 * GRID_SIZE});
            wall_position.push_back({i, WINDOW_HEIGHT - 3 * GRID_SIZE});
        }
    }
    else if (wallType[2] == 1)
    {
        for (int i = 2 * GRID_SIZE; i < WINDOW_HEIGHT - 2 * GRID_SIZE; i += GRID_SIZE)
        {
            wall_position.push_back({2 * GRID_SIZE, i});
            wall_position.push_back({WINDOW_WIDTH / 2 - 6 * GRID_SIZE, i});
            wall_position.push_back({WINDOW_WIDTH / 2 - 2 * GRID_SIZE, i});
            wall_position.push_back({WINDOW_WIDTH / 2 + 2 * GRID_SIZE, i});
            wall_position.push_back({WINDOW_WIDTH / 2 + 6 * GRID_SIZE, i});
            wall_position.push_back({WINDOW_WIDTH - 3 * GRID_SIZE, i});
        }
    }
    else if (wallType[3] == 1)
    {
        for (int i = 2 * GRID_SIZE; i < WINDOW_WIDTH / 2 - 3 * GRID_SIZE; i += GRID_SIZE)
        {
            wall_position.push_back({i, 2 * GRID_SIZE});
            wall_position.push_back({i, WINDOW_HEIGHT / 2});
            wall_position.push_back({i, WINDOW_HEIGHT - 3 * GRID_SIZE});
        }

        for (int i = WINDOW_WIDTH / 2 + 3 * GRID_SIZE; i < WINDOW_WIDTH - 2 * GRID_SIZE; i += GRID_SIZE)
        {
            wall_position.push_back({i, 2 * GRID_SIZE});
            wall_position.push_back({i, WINDOW_HEIGHT / 2});
            wall_position.push_back({i, WINDOW_HEIGHT - 3 * GRID_SIZE});
        }

        for (int i = 3 * GRID_SIZE; i < WINDOW_HEIGHT / 2 - 3 * GRID_SIZE; i += GRID_SIZE)
        {
            wall_position.push_back({2 * GRID_SIZE, i});
            wall_position.push_back({WINDOW_WIDTH / 2 - 2 * GRID_SIZE, i});
            wall_position.push_back({WINDOW_WIDTH / 2 + GRID_SIZE, i});
            wall_position.push_back({WINDOW_WIDTH - 3 * GRID_SIZE, i});
        }

        for (int i = WINDOW_HEIGHT / 2 + 4 * GRID_SIZE; i < WINDOW_HEIGHT - 3 * GRID_SIZE; i += GRID_SIZE)
        {
            wall_position.push_back({2 * GRID_SIZE, i});
            wall_position.push_back({WINDOW_WIDTH / 2 - 2 * GRID_SIZE, i});
            wall_position.push_back({WINDOW_WIDTH / 2 + GRID_SIZE, i});
            wall_position.push_back({WINDOW_WIDTH - 3 * GRID_SIZE, i});
        }
    }
}

void Wall::draw()
{

    for (auto &p : wall_position)
    {
        putimage(p.x, p.y, wallImg);
    }
    
}

void Wall::generateRandomly(Point& food, Snake& snake, SecondSnake& secondSnake)
{
    int x = rand() % ((WINDOW_WIDTH - 2 * GRID_SIZE) / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
    int y = rand() % ((WINDOW_HEIGHT - 2 * GRID_SIZE) / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
    if (x == food.x && y == food.y)
    {
        generateRandomly(food, snake, secondSnake);
        return;
    }
    for (auto &p : snake.getBody())
    {
        if (x == p.x && y == p.y)
        {
            generateRandomly(food, snake, secondSnake);
            return;
        }
    }
    for (auto &p : secondSnake.getBody())
    {
        if (x == p.x && y == p.y)
        {
            generateRandomly(food, snake, secondSnake);
            return;
        }
    }
    Point p = {x, y};
    wall_position.push_back(p);
}