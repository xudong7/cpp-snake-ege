#pragma once

#include <vector>  
#include <ege.h>
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
int score = 0;
int secondScore = 0;
bool gameOver = false;
int mode[2] = {1, 0};

struct Point 
{  
    int x, y;  
};  

class Menu
{

public:
    Menu() {}
    void showMenu();
    void chooseGameMode();
    void howToPlay();
    void listenMenu();
    void listenHowToPlay();
    void listenGameMode();
    void setMode(int m1, int m2);
    void reset();
};