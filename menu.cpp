#include "menu.h"
#include "game.h"

void Menu::showMenu()
{
    setfont(40, 0, "consolas");
    setcolor(GREEN);
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 - 50, "Welcome to Snake Game");
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2, "Press 'r' to choose different game mode");
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2 + 30, "Press 'h' to know how to play");
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2 + 60, "Press 'q' to exit the game");
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
    outtextxy(WINDOW_WIDTH/3 + 30, WINDOW_HEIGHT/2 + 120, "Press 'r' to go back to main menu");
    outtextxy(WINDOW_WIDTH/3 + 30, WINDOW_HEIGHT/2 + 150, "Press 'q' to exit the game");
}

void Menu::chooseWallType()
{
    setfont(40, 0, "consolas");
    setcolor(GREEN);
    outtextxy(WINDOW_WIDTH/3 + 30, WINDOW_HEIGHT/2 - 50, "Choose Wall Type");
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2, "Press '1' to choose simple mode");
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2 + 30, "Press '2' to choose medium mode");
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2 + 60, "Press '3' to choose complex mode");
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2 + 90, "Press '4' to choose demon mode");
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2 + 120, "Press 'r' to go back to main menu");
    outtextxy(WINDOW_WIDTH/3 + 70, WINDOW_HEIGHT/2 + 150, "Press 'q' to exit the game");
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
    if (key == 'r')
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
        setMode(1, 0);
        chooseWallType();
        listenChooseWallType();
    }
    else if (key == '2')
    {
        setMode(0, 1);
        chooseWallType();
        listenChooseWallType();
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

void Menu::listenChooseWallType()
{
    char key = getch();
    if (key == '1')
    {
        isRunning = true;
        wallType[0] = 1;
        wallType[1] = wallType[2] = wallType[3] = 0;
    }
    else if (key == '2')
    {
        isRunning = true;
        wallType[1] = 1;
        wallType[0] = wallType[2] = wallType[3] = 0;
    }
    else if (key == '3')
    {
        isRunning = true;
        wallType[2] = 1;
        wallType[0] = wallType[1] = wallType[3] = 0;
    }
    else if (key == '4')
    {
        isRunning = true;
        wallType[3] = 1;
        wallType[0] = wallType[1] = wallType[2] = 0;
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
        listenChooseWallType();
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