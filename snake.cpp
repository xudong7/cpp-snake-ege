#include "snake.h"  

Snake::Snake() : direction(3), length(2), gameOver(false) 
{  
    srand(time(nullptr)); 
    head.x = WINDOW_WIDTH / 2 - 8 * GRID_SIZE;  
    head.y = WINDOW_HEIGHT / 2 - 6 * GRID_SIZE;  
    body.push_back({head.x, head.y - GRID_SIZE});  
    body.push_back({head.x, head.y});  

    setImages();
}  
  
int Snake::getScore()
{
    return score;
}

void Snake::setImages()
{
    snakeHeadImg = newimage();
    snakeBodyImg = newimage();
    getimage(snakeHeadImg, "./cpp-snake-ege/assets/snakeHead.jpg");
    getimage(snakeBodyImg, "./cpp-snake-ege/assets/snakeTail.jpg");
    // getimage(snakeHeadImg, "./assets/snakeHead.jpg"); // exe file
    // getimage(snakeBodyImg, "./assets/snakeTail.jpg"); // exe file
}

Snake::~Snake() {  
    delimage(snakeHeadImg);
    delimage(snakeBodyImg);
}  

void Snake::printScore()
{
    char str[100];
    setcolor(WHITE);
    sprintf(str, "Score: %d", score);
    outtextxy(0, 0, str);
}

void Snake::draw()
{   
    for (size_t i = 0; i < body.size(); ++i) {  
        PIMAGE img = (i == body.size()-1) ? snakeHeadImg : snakeBodyImg;  
        putimage(body[i].x, body[i].y, img);  
    }  
}  

bool Snake::ifAteFood(Point& newHead, Point& food)
{
    if (newHead.x == food.x && newHead.y == food.y) 
    {  
        length++;  
        score += 1;
        if (score % 5 == 0)
        {
            VELOCITY += DELTA_VELOCITY;
        }
        return true;
    } 
    else 
    {  
        body.erase(body.begin());  
        return false;
    }  
}

void Snake::ifAteShit(Point& newHead, vector<Point>& shit_position)
{
    for (auto it = shit_position.begin(); it != shit_position.end(); )  
    {  
        if (newHead.x == it->x && newHead.y == it->y)  
        {  
            score -= 5; 
            if (score % 5 == 0)  
            {  
                VELOCITY += 2 * DELTA_VELOCITY; 
            }  
            it = shit_position.erase(it); 
        }  
        else  
        {  
            ++it; 
        }  
    }  
}

void Snake::checkGameOver(Point& newHead, vector<Point>& wall_position)
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

bool Snake::move(vector<Point>& wall_position, Point& food, vector<Point>& shit_position) 
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
    if (newHead.x >= WINDOW_WIDTH) newHead.x = 0;
    if (newHead.y < 0) newHead.y = WINDOW_HEIGHT - GRID_SIZE;
    if (newHead.y >= WINDOW_HEIGHT) newHead.y = 0;

    bool ifAte = ifAteFood(newHead, food);
    ifAteShit(newHead, shit_position);

    checkGameOver(newHead, wall_position); 

    head = newHead;  
    body.push_back(head);
    return ifAte;
}  
  
void Snake::changeDirection(char key) 
{  
    switch (key) 
    {  
        case 'a':  
            if (direction != 2) direction = 0;  
            break;  
        case 'w':  
            if (direction != 3) direction = 1;  
            break;  
        case 'd':  
            if (direction != 0) direction = 2;  
            break;  
        case 's':  
            if (direction != 1) direction = 3;  
            break;  
    }   
}  
  
int Snake::getLength()
{  
    return length;  
}

bool Snake::isGameOver()
{  
    return gameOver;  
}  
  

Point Snake::getHead()
{
    return head;
}

vector<Point>& Snake::getBody()
{
    return body;
}

void Snake::setGameOver()
{
    gameOver = true;
}