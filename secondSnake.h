#pragma once
  
#include "menu.h"

class SecondSnake 
{  
private:  
    PIMAGE snakeHeadImg;
    PIMAGE snakeBodyImg;
    PIMAGE foodImg;

    vector<Point> body;  
    Point head;  
    int direction; // 0: left, 1: up, 2: right, 3: down  
    int length;  
    bool gameOver;   
 
public:  
    SecondSnake();  
    ~SecondSnake();
    void setImages();
    void draw();  
    bool move(vector<Point>& wall_position, Point& food);  
    void printScore();
    void changeDirection(char key);  
    bool ifAteFood(Point& newHead, Point& food);
    void checkGameOver(Point& newHead, vector<Point>& wall_position);
    bool isGameOver();  
    int getLength();
    Point getHead();
    vector<Point>& getBody();
    void setGameOver();
};  
  