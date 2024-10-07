#include "menu.h"
#include "game.h"

Menu::Menu()
{
    setImages();
}

void Menu::setImages()
{
    snakeTitle = newimage();
    gameOverPic = newimage();
    leftsnakepic = newimage();
    rightsnakepic = newimage();
    gameWin = newimage();
    getimage(snakeTitle, "./cpp-snake-ege/assets/snakeTitle.jpg");
    getimage(gameOverPic, "./cpp-snake-ege/assets/gameoverpic.jpg");
    getimage(leftsnakepic, "./cpp-snake-ege/assets/leftsnakepic.jpg");
    getimage(rightsnakepic, "./cpp-snake-ege/assets/rightsnakepic.jpg");
    getimage(gameWin, "./cpp-snake-ege/assets/win.jpg");
}

void Menu::showMenu()
{
    putimage(WINDOW_WIDTH/3, WINDOW_HEIGHT/3, snakeTitle);
    putimage(WINDOW_WIDTH/3 - 70, WINDOW_HEIGHT/3 + 10, rightsnakepic);
    putimage(WINDOW_WIDTH/3 + 300, WINDOW_HEIGHT/3 + 10, leftsnakepic);
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2, "-- Press 'e' to play game --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 30, "-- Press 'r' to choose game mode --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 60, "-- Press 'h' to know how to play --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 90, "-- Press 'q' to exit the game    --");
}

void Menu::chooseGameMode()
{
    putimage(WINDOW_WIDTH/3, WINDOW_HEIGHT/3, snakeTitle);
    putimage(WINDOW_WIDTH/3 - 70, WINDOW_HEIGHT/3 + 10, rightsnakepic);
    putimage(WINDOW_WIDTH/3 + 300, WINDOW_HEIGHT/3 + 10, leftsnakepic);
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2, "-- Press '1' single player mode --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 30, "-- Press '2' double player mode --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 60, "-- Press 'r' back to main menu  --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 90, "-- Press 'q' to exit the game   --");
}

void Menu::howToPlay()
{
    putimage(WINDOW_WIDTH/3, WINDOW_HEIGHT/3, snakeTitle);
    putimage(WINDOW_WIDTH/3 - 70, WINDOW_HEIGHT/3 + 10, rightsnakepic);
    putimage(WINDOW_WIDTH/3 + 300, WINDOW_HEIGHT/3 + 10, leftsnakepic);
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    outtextxy(WINDOW_WIDTH/3 + 20, WINDOW_HEIGHT/2, "w and ¡ü => up");
    outtextxy(WINDOW_WIDTH/3 + 150, WINDOW_HEIGHT/2, "s and ¡ý => down");
    outtextxy(WINDOW_WIDTH/3 + 20, WINDOW_HEIGHT/2 + 30, "a and ¡û => left");
    outtextxy(WINDOW_WIDTH/3 + 150, WINDOW_HEIGHT/2 + 30, "d and ¡ú => right");
    outtextxy(WINDOW_WIDTH/3 + 20, WINDOW_HEIGHT/2 + 60, "Eat food to get score");
    outtextxy(WINDOW_WIDTH/3 + 20, WINDOW_HEIGHT/2 + 90, "Don't hit the wall or yourself");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 150, "-- Press 'r' to go back to main menu --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 180, "-- Press 'q' to exit the game --");
}

void Menu::chooseWallType()
{
    putimage(WINDOW_WIDTH/3, WINDOW_HEIGHT/3, snakeTitle);
    putimage(WINDOW_WIDTH/3 - 70, WINDOW_HEIGHT/3 + 10, rightsnakepic);
    putimage(WINDOW_WIDTH/3 + 300, WINDOW_HEIGHT/3 + 10, leftsnakepic);
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2, "-- Press '1' to choose simple mode --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 30, "-- Press '2' to choose medium mode --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 60, "-- Press '3' to choose complex mode --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 90, "-- Press '4' to choose demon mode --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 120, "-- Press 'r' to go back to main menu --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 150, "-- Press 'q' to exit the game --");
}

void Menu::stopMenu()
{
    isRunning = false;
    putimage(WINDOW_WIDTH/3, WINDOW_HEIGHT/3, snakeTitle);
    putimage(WINDOW_WIDTH/3 - 70, WINDOW_HEIGHT/3 + 10, rightsnakepic);
    putimage(WINDOW_WIDTH/3 + 300, WINDOW_HEIGHT/3 + 10, leftsnakepic);
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2, "-- Press space back to the game --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 30, "-- Press 'r' to go back to main menu --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 60, "-- Press 'q' to exit the game --");
}

void Menu::showGameOver()
{
    cleardevice();
    putimage(WINDOW_WIDTH/4, WINDOW_HEIGHT/3 - 20, gameOverPic);
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    char buffer[100];
    if (mode[0] == 1 && mode[1] == 0)
    {
        sprintf(buffer, "   Your score: %d", score);
    }
    else
    {
        sprintf(buffer, "   first score: %d, second score: %d", score, secondScore);
    }
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2, buffer);
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 30, "-- Press 'r' back to main menu --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 60, "-- Press 'q' to exit the game --");
}

void Menu::showGameWin()
{
    cleardevice();
    putimage(WINDOW_WIDTH/3, WINDOW_HEIGHT/6, gameWin);
    setfont(20, 0, "consolas");
    setcolor(WHITE);
    // char buffer[100];
    // if (mode[0] == 1 && mode[1] == 0)
    // {
    //     sprintf(buffer, "   Your score: %d", score);
    // }
    // else
    // {
    //     sprintf(buffer, "   first score: %d, second score: %d", score, secondScore);
    // }
    // outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2, buffer);
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 30, "-- Press 'r' back to main menu --");
    outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 60, "-- Press 'q' to exit the game --");
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
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2, "-- Press 'e' to play game --");
        Sleep(200);
        cleardevice();
        isRunning = true;
    }
    else if (key == 'r')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2, "-- Press 'r' to choose game mode --");
        Sleep(200);
        cleardevice();
        chooseGameMode();
        listenGameMode();
    }
    else if (key == 'h')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 30, "-- Press 'h' to know how to play --");
        Sleep(200);
        cleardevice();
        howToPlay();
        listenHowToPlay();
    }
    else if (key == 'q')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 60, "-- Press 'q' to exit the game    --");
        Sleep(200);
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
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 150, "-- Press 'r' to go back to main menu --");
        Sleep(200);
        cleardevice();
        showMenu();
        listenMenu();
    }
    else if (key == 'q')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 180, "-- Press 'q' to exit the game --");
        Sleep(200);
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
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2, "-- Press '1' single player mode --");
        Sleep(200);
        setMode(1, 0);
        cleardevice();
        chooseWallType();
        listenChooseWallType();
    }
    else if (key == '2')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 30, "-- Press '2' double player mode --");
        Sleep(200);
        setMode(0, 1);
        cleardevice();
        chooseWallType();
        listenChooseWallType();
    }
    else if (key == 'r')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 60, "-- Press 'r' back to main menu  --");
        Sleep(200);
        cleardevice();
        showMenu();
        listenMenu();
    }
    else if (key == 'q')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 90, "-- Press 'q' to exit the game   --");
        Sleep(200);
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
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2, "-- Press '1' to choose simple mode --");
        Sleep(200);
        isRunning = true;
        wallType[0] = 1;
        wallType[1] = wallType[2] = wallType[3] = 0;
    }
    else if (key == '2')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 30, "-- Press '2' to choose medium mode --");
        Sleep(200);
        isRunning = true;
        wallType[1] = 1;
        wallType[0] = wallType[2] = wallType[3] = 0;
    }
    else if (key == '3')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 60, "-- Press '3' to choose complex mode --");
        Sleep(200);
        isRunning = true;
        wallType[2] = 1;
        wallType[0] = wallType[1] = wallType[3] = 0;
    }
    else if (key == '4')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 90, "-- Press '4' to choose demon mode --");
        Sleep(200);
        isRunning = true;
        wallType[3] = 1;
        wallType[0] = wallType[1] = wallType[2] = 0;
    }
    else if (key == 'r')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 120, "-- Press 'r' to go back to main menu --");
        Sleep(200);
        cleardevice();
        showMenu();
        listenMenu();
    }
    else if (key == 'q')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 150, "-- Press 'q' to exit the game --");
        Sleep(200);
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
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2, "-- Press space back to the game --");
        Sleep(200);
        isRunning = true;
    }
    else if (key == 'r')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 30, "-- Press 'r' to go back to main menu --");
        Sleep(200);
        reset();
    }
    else if (key == 'q')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 60, "-- Press 'q' to exit the game --");
        Sleep(200);
        score = secondScore = 0;
        isRunning = false;
        isQuit = true;
    }
    else
    {
        stopMenu();
    }
}

void Menu::listenGameOver()
{
    char key = getch();
    if (key == 'r')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 30, "-- Press 'r' back to main menu --");
        Sleep(200);
        reset();
    }
    else if (key == 'q')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 60, "-- Press 'q' to exit the game --");
        Sleep(200);
        score = secondScore = 0;
        isRunning = false;
        isQuit = true;
    }
    else
    {
        listenGameOver();
    }
}

void Menu::listenGameWin()
{
    char key = getch();
    if (key == 'r')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 30, "-- Press 'r' back to main menu --");
        Sleep(200);
        reset();
    }
    else if (key == 'q')
    {
        setcolor(GREEN);
        outtextxy(WINDOW_WIDTH/3, WINDOW_HEIGHT/2 + 60, "-- Press 'q' to exit the game --");
        Sleep(200);
        score = secondScore = 0;
        isRunning = false;
        isQuit = true;
    }
    else
    {
        listenGameWin();
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