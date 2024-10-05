#include "game.h"
#include "game.cpp"
#include "snake.h"
#include "snake.cpp"
#include "menu.h"
#include "menu.cpp"

// all global parameters in menu.h
int main() 
{  
    setinitmode(0);
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT); 

    Game game;
    game.run();
  
    getch(); 
    closegraph(); 
    return 0;  
}