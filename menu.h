#pragma once

#include <vector>  
#include <graphics.h> 
#include <conio.h> 
#include <cstdlib>  
#include <ctime>   
#include <string>
#include <windows.h>
#include <iostream>
#include <algorithm>

#include <cstdio>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

using namespace std;
#define GRID_SIZE 20  
#define WINDOW_WIDTH 1000  
#define WINDOW_HEIGHT 600  
#define DELTA_VELOCITY 0.5
double VELOCITY = 6;
double SECOND_VELOCITY = 6;
bool isRunning = false;
bool isQuit = false;
int score = 0;
int secondScore = 0;
// bool gameOver = false;
int mode[2] = {1, 0};
int wallType[4] = {1, 0, 0, 0};
int wantScore = 2;



struct Point 
{  
    int x, y;  
};  

class Menu
{
    PIMAGE snakeTitle;
    PIMAGE gameOverPic;
    PIMAGE leftsnakepic;
    PIMAGE rightsnakepic;
    PIMAGE gameWin;
public:
    Menu();
    void setImages();
    void showMenu();
    void chooseGameMode();
    void howToPlay();
    void chooseWallType();
    void stopMenu();
    void showGameOver();
    void showGameWin();
    void listenMenu();
    void listenHowToPlay();
    void listenGameMode();
    void listenChooseWallType();
    void listenStopMenu();
    void listenGameOver();
    void listenGameWin();
    void setMode(int m1, int m2);
    void reset();
};