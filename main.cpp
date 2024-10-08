#include "game.h"
#include "game.cpp"
#include "menu.h"
#include "menu.cpp"
#include "wall.h"
#include "wall.cpp"
#include "food.h"
#include "food.cpp"
#include "snake.h"
#include "snake.cpp"
#include "secondSnake.h"
#include "secondSnake.cpp"
#include "shit.h"
#include "shit.cpp"

// all global parameters in menu.h
int main() 
{  
    MUSIC bgm;

    bgm.OpenFile("cpp-snake-ege/assets/bp_music.wav");
    // bgm.OpenFile("./assets/bp_music.wav");
    bgm.Play();

    setinitmode(0);
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT); 

    Game game;
    game.run();
  
    getch(); 
    closegraph(); 
    return 0;  
}