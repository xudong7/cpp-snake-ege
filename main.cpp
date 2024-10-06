#include "game.h"
#include "game.cpp"
#include "snake.h"
#include "snake.cpp"
#include "menu.h"
#include "menu.cpp"
#include "wall.h"
#include "wall.cpp"

void backgroundMusic()
{
    mciSendString("open assets/bp_music.mp3 alias bgm", NULL, 0, NULL);
    mciSendString("play bgm", NULL, 0, NULL);
}

// all global parameters in menu.h
int main() 
{  
    backgroundMusic();

    setinitmode(0);
    initgraph(WINDOW_WIDTH, WINDOW_HEIGHT); 

    Game game;
    game.run();
  
    getch(); 
    closegraph(); 
    return 0;  
}