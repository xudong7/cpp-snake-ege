#include "shit.h"
#include "menu.h"

Shit::Shit()
{
    setImages(); 
}

void Shit::setImages()
{
    shitImg = newimage();
    getimage(shitImg, "./cpp-snake-ege/assets/shit.jpg");
    // getimage(shitImg, "./assets/shit.jpg"); // exe file
}

void Shit::draw(vector<Point>& wall_position, int ifAteShit)
{
    generateRandomly(wall_position, ifAteShit);
    putimage(shit.x, shit.y, shitImg);
}

void Shit::generateRandomly(vector<Point>& wall_position, int ifAteShit)
{
    if (ifAteShit)
    {
        int x = rand() % ((WINDOW_WIDTH - 2 * GRID_SIZE) / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
        int y = rand() % ((WINDOW_HEIGHT - 2 * GRID_SIZE) / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
        for (auto &p : wall_position)
        {
            if (x == p.x && y == p.y)
            {
                generateRandomly(wall_position, ifAteShit);
                return;
            }
        }
        shit = {x, y};
    }

}

Shit::~Shit()
{
    delimage(shitImg);
}
