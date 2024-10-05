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
using namespace std;
#define GRID_SIZE 20  
#define WINDOW_WIDTH 1000  
#define WINDOW_HEIGHT 600  
int VELOCITY = 6;
int GLOBAL_RATE = 200 - VELOCITY;
bool isRunning = false;
int score = 0;
bool gameOver = false;

class Menu
{

public:
    Menu();
    void showMenu();
    void listenMenu();
    void reset();
};