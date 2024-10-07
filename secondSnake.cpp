#include "secondSnake.h"  

SecondSnake::SecondSnake() : direction(3), length(2), gameOver(false) 
{  
    srand(time(nullptr)); 
    head.x = WINDOW_WIDTH / 2 + 8 * GRID_SIZE;  
    head.y = WINDOW_HEIGHT / 2 + 3 * GRID_SIZE;  
    body.push_back({head.x, head.y - GRID_SIZE});  
    body.push_back({head.x, head.y});  

    setImages();
}  

void SecondSnake::setImages()
{
    snakeHeadImg = newimage();
    snakeBodyImg = newimage();
    getimage(snakeHeadImg, "./cpp-snake-ege/assets/secondSnakeHead.jpg");
    getimage(snakeBodyImg, "./cpp-snake-ege/assets/secondSnakeTail.jpg");
    // getimage(foodImg, "./assets/secondSnakeHead.jpg"); // exe file
    // getimage(foodImg, "./assets/secondSnakeTail.jpg"); // exe file
}

SecondSnake::~SecondSnake() {  
    delimage(snakeHeadImg);
    delimage(snakeBodyImg);
}  

void SecondSnake::printScore()
{
    char str[100];
    setcolor(WHITE);
    sprintf(str, "secondScore: %d", secondScore);
    outtextxy(WINDOW_WIDTH-6.4*GRID_SIZE, 0, str);
}

void SecondSnake::draw()
{   
    for (size_t i = 0; i < body.size(); ++i) {  
        PIMAGE img = (i == body.size()-1) ? snakeHeadImg : snakeBodyImg;  
        putimage(body[i].x, body[i].y, img);  
    }  
}  

bool SecondSnake::ifAteFood(Point& newHead, Point& food)
{
    if (newHead.x == food.x && newHead.y == food.y) 
    {  
        length++;  
        secondScore += 1;
        if (secondScore % 5 == 0)
        {
            SECOND_VELOCITY += DELTA_VELOCITY;
        }
        return true;
    } 
    else 
    {  
        body.erase(body.begin());  
        return false;
    }  
}

void SecondSnake::checkGameOver(Point& newHead, vector<Point>& wall_position)
{
    for (auto &p : wall_position)
    {
        if (p.x == newHead.x && p.y == newHead.y)
        {
            gameOver = true;
            break;
        }
    }

    for (auto &p : body) 
    {  
        if (p.x == newHead.x && p.y == newHead.y) 
        {  
            gameOver = true;  
            break;  
        }  
    }  

    for (auto &p: wall_position)
    {
        if (p.x == newHead.x && p.y == newHead.y)
        {
            gameOver = true;
            break;
        }
    }

    // if (newHead.x < GRID_SIZE 
    //     || newHead.x >= WINDOW_WIDTH - GRID_SIZE 
    //     || newHead.y < GRID_SIZE 
    //     || newHead.y >= WINDOW_HEIGHT - GRID_SIZE) 
    // {  
    //     gameOver = true;  
    // }  
}

bool SecondSnake::move(vector<Point>& wall_position, Point& food) 
{  
    Point newHead = head;  
    switch (direction) 
    {  
        case 0: newHead.x -= GRID_SIZE; break;  
        case 1: newHead.y -= GRID_SIZE; break;  
        case 2: newHead.x += GRID_SIZE; break;  
        case 3: newHead.y += GRID_SIZE; break;  
    }  

    if (newHead.x < 0) newHead.x = WINDOW_WIDTH - GRID_SIZE;
    if (newHead.x >= WINDOW_WIDTH) newHead.x = GRID_SIZE;
    if (newHead.y < 0) newHead.y = WINDOW_HEIGHT - GRID_SIZE;
    if (newHead.y >= WINDOW_HEIGHT) newHead.y = GRID_SIZE;

    bool ifAte = ifAteFood(newHead, food);

    checkGameOver(newHead, wall_position); 

    head = newHead;  
    body.push_back(head);
    return ifAte;
}  
  
void SecondSnake::changeDirection(char key) 
{  
    switch (key) 
    {  
        case key_left:  
            if (direction != 2) direction = 0;  
            break;  
        case key_up:  
            if (direction != 3) direction = 1;  
            break;  
        case key_right:  
            if (direction != 0) direction = 2;  
            break;  
        case key_down:  
            if (direction != 1) direction = 3;  
            break;  
    }   
}  
  
int SecondSnake::getLength()
{  
    return length;  
}

bool SecondSnake::isGameOver()
{  
    return gameOver;  
}  
  

Point SecondSnake::getHead()
{
    return head;
}

vector<Point>& SecondSnake::getBody()
{
    return body;
}

void SecondSnake::setGameOver()
{
    gameOver = true;
}