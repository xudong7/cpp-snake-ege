#include "menu.h"
#include "game.h"

void Menu::showMenu()
{
    setfont(40, 0, "consolas");
    setcolor(GREEN);
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 - 50, "Welcome to Snake Game");
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2, "Press 'e' to start the game");
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2 + 30, "Press 'r' to choose different game mode");
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2 + 60, "Press 'h' to know how to play");
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2 + 90, "Press 'q' to exit the game");
}

void Menu::chooseGameMode()
{
    setfont(40, 0, "consolas");
    setcolor(GREEN);
    outtextxy(WINDOW_WIDTH/3 + 30, WINDOW_HEIGHT/2 - 50, "Change Game Mode");
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2, "Press '1' single player mode");
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2 + 30, "Press '2' double player mode");
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2 + 60, "Press 'r' to go back to main menu");
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2 + 90, "Press 'q' to exit the game");
}

void Menu::howToPlay()
{
    setfont(40, 0, "consolas");
    setcolor(GREEN);
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 - 50, "How to Play Snake Game");
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    outtextxy(WINDOW_WIDTH/3 + 30, WINDOW_HEIGHT/2, "Use 'w','a','s','d' keys to move the snake");
    outtextxy(WINDOW_WIDTH/3 + 30, WINDOW_HEIGHT/2 + 30, "Eat the food to increase the length of the snake");
    outtextxy(WINDOW_WIDTH/3 + 30, WINDOW_HEIGHT/2 + 60, "Avoid hitting the walls and the snake itself");
    outtextxy(WINDOW_WIDTH/3 + 30, WINDOW_HEIGHT/2 + 90, "Press 'r' to go back to main menu");
    outtextxy(WINDOW_WIDTH/3 + 30, WINDOW_HEIGHT/2 + 120, "Press 'q' to exit the game");
}

void Menu::stopMenu()
{
    isRunning = false;
    setfont(40, 0, "consolas");
    setcolor(GREEN);
    outtextxy(WINDOW_WIDTH/3 + 30, WINDOW_HEIGHT/2 - 50, "Game Paused");
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    outtextxy(WINDOW_WIDTH/3 + 30, WINDOW_HEIGHT/2, "enter space back to the game");
    outtextxy(WINDOW_WIDTH/3 + 30, WINDOW_HEIGHT/2 + 30, "Press 'r' to go back to main menu");
    outtextxy(WINDOW_WIDTH/3 + 30, WINDOW_HEIGHT/2 + 60, "Press 'q' to exit the game");
}

void Menu::setMode(int m1, int m2)
{
    mode[0] = m1;
    mode[1] = m2;
}

void Menu::listenMenu()
{
    char key = getch();
    if (key == 'e')
    {
        isRunning = true;
        setMode(1, 0);
    }
    else if (key == 'r')
    {
        cleardevice();
        chooseGameMode();
        listenGameMode();
    }
    else if (key == 'h')
    {
        cleardevice();
        howToPlay();
        listenHowToPlay();
    }
    else if (key == 'q')
    {
        score = secondScore = 0;
        isRunning = false;
        isQuit = true;
    }
    else
    {
        listenMenu();
    }
}

void Menu::listenHowToPlay()
{
    char key = getch();
    if (key == 'r')
    {
        cleardevice();
        showMenu();
        listenMenu();
    }
    else if (key == 'q')
    {
        score = secondScore = 0;
        isRunning = false;
        isQuit = true;
    }
    else
    {
        listenHowToPlay();
    }
}

void Menu::listenGameMode()
{
    char key = getch();
    if (key == '1')
    {
        isRunning = true;
        setMode(1, 0);
    }
    else if (key == '2')
    {
        isRunning = true;
        setMode(0, 1);
    }
    else if (key == 'r')
    {
        cleardevice();
        showMenu();
        listenMenu();
    }
    else if (key == 'q')
    {
        score = secondScore = 0;
        isRunning = false;
        isQuit = true;
    }
    else
    {
        listenGameMode();
    }
}

void Menu::listenStopMenu()
{
    char key = getch();
    if (key == ' ')
    {
        isRunning = true;
    }
    else if (key == 'r')
    {
        cleardevice();
        showMenu();
        listenMenu();
    }
    else if (key == 'q')
    {
        score = secondScore = 0;
        isRunning = false;
        isQuit = true;
    }
    else
    {
        stopMenu();
    }
}

void Menu::reset()
{
    isRunning = false;

    cleardevice();
    Game game;
    score = secondScore = 0;
    game.run();
}