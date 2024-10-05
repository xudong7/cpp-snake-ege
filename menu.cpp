#include "menu.h"
#include "game.h"

Menu::Menu()
{

}

void Menu::showMenu()
{
    setfont(40, 0, "consolas");
    setcolor(GREEN);
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 - 50, "Welcome to Snake Game");
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    outtextxy(WINDOW_WIDTH/3 + 80, WINDOW_HEIGHT/2, "Press 'e' to start the game");
    outtextxy(WINDOW_WIDTH/3 + 80, WINDOW_HEIGHT/2 + 30, "Press 'q' to exit the game");
}

void Menu::listenMenu()
{
    char key = getch();
    if (key == 'e')
    {
        isRunning = true;
    }
    else if (key == 'q')
    {
        isRunning = false;
    }
}

void Menu::reset()
{
    isRunning = false;

    cleardevice();
    Game game;
    game.run();
}