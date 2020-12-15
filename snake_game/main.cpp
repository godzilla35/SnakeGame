#include <Windows.h>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <queue>

using namespace std;


#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define MAX_EDGE 100

void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

class Snake
{
private:
    vector<pair<int, int>> body;

public:
    Snake()
    {
        body.push_back(make_pair(1, 1));
    }

    
    void move(int direction)
    {
        if (body.size() == 0) return;

        pair<int, int> top = body[0];
        switch (direction)
        {
        case LEFT:
            if(top.first > 0 ) top.first--;
            break;
        case RIGHT:
            if (top.first < MAX_EDGE) top.first++;
            break;
        case UP:
            if (top.second > 0) top.second--;
            break;
        case DOWN:
            if (top.second < MAX_EDGE) top.second++;
            break;
        }

        for (int i = 1; i < body.size(); i++)
        {
            body[i] = body[i - 1];
        }
        body[0] = top;

    }
    void draw()
    {
        for (auto i : body)
        {
            gotoxy(i.first, i.second);
            printf("@");
        }
    }
};



void draw_edge()
{

}

bool inc_snake_len = false;
int main()
{
    char input = 0;
    Snake snake;
    snake.draw();
    
    while (1)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == -32)
            {
                input = _getch();
                if (inc_snake_len == false)
                {
                    //gotoxy(x, y);
                    //printf(" ");
                }
                else
                {
                    inc_snake_len = false;
                }
                snake.move(input);
                snake.draw();

            }
            else if(input == '1')
            {
                inc_snake_len = true;
                //break;
            }
            
        }
    }
     


    return 0;
}