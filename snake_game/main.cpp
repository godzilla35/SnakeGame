#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include <queue>
#include <vector>

using namespace std;

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80


#define MAX_EDGE 20

int cur_target_x, cur_target_y;

char target_char = '#';

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void gotoxy_draw(int x, int y, char c) {
    gotoxy(x, y);
    printf("%c", c);
}

class Target {
public:
    int target_cnt, x, y;
    Target() {
        target_cnt = 0;
        cur_target_x = x = rand() % (MAX_EDGE - 1) + 1;
        cur_target_y = y = rand() % (MAX_EDGE - 1) + 1;

        gotoxy_draw(x, y, target_char);
    }

    void CreateNewTarget(const vector<pair<int, int>>& snake_body) {
        target_cnt++;
        bool retry = true;
        while (retry) {
            cur_target_x = x = rand() % (MAX_EDGE - 1) + 1;
            cur_target_y = y = rand() % (MAX_EDGE - 1) + 1;

            retry = false;
            for (auto p : snake_body) {
                if (p.first == x && p.second == y) {
                    retry = true;
                    break;
                }
            }
        }

        gotoxy_draw(x, y, target_char);
    }
};


enum MoveStatus
{
    none,
    err,
    meet_target,
    meet_edge,
    meet_snake
};


class Snake {

private:

    bool IsTarget(pair<int, int>& pos) {
        return (pos.first == cur_target_x && pos.second == cur_target_y);
    }

    bool IsBody(pair<int, int>& pos) {
        for (auto p : body) {
            if (pos.first == p.first && pos.second == p.second) return true;
        }
        return false;
    }

    bool IsEdge(pair<int, int>& pos) {
        return (pos.first == 0 || 
                pos.first == MAX_EDGE ||
                pos.second == 0 || 
                pos.second == MAX_EDGE);
    }

public:

    
    int direction;
    int clock;
    vector<pair<int, int>> body;
    Snake() { 
        body.push_back(make_pair(1, 1)); 
        direction = RIGHT;
        gotoxy_draw(body[0].first, body[0].second, '@');
        clock = 1000;
    }

    void speed_up()
    {
        // 최고 속도
        if (clock == 100) return;

        clock -= 100;
    }

    


    MoveStatus move(int direction) {
        if (body.size() == 0)
            return err;

        MoveStatus ret = none;
        int body_len = body.size();

        pair<int, int> top = body[0];
        switch (direction) {
        case LEFT:
            if (top.first > 0)
                top.first--;
            break;
        case RIGHT:
            if (top.first < MAX_EDGE)
                top.first++;
            break;
        case UP:
            if (top.second > 0)
                top.second--;
            break;
        case DOWN:
            if (top.second < MAX_EDGE)
                top.second++;
            break;
        }

        // 음식을 먹으면
        if (IsTarget(top)) {
            gotoxy_draw(top.first, top.second, ' ');
            
            body.push_back(body.back());
            for (int i = body.size() - 1; i > 0 ; i--) {
                body[i] = body[i - 1];
            }

            ret = meet_target;

        }
        else if (IsBody(top)) {
            return meet_snake;
        }
        else if (IsEdge(top)) {
            return meet_edge;
        }
        else {
            // 마지막 몸 삭제
            gotoxy_draw(body[body_len - 1].first, body[body_len - 1].second, ' ');
            

            for (int i = body.size() - 1; i > 0; i--) {
                body[i] = body[i - 1];
            }
            ret = none;
        }

        body[0] = top;
        gotoxy_draw(body[0].first, body[0].second, '@');
        

        return ret;
    }

};

void draw_map()
{
    gotoxy(0, 0);
    printf("=====================\n");
    for(int i = 1; i< MAX_EDGE; i++) printf("=                   =\n");
    printf("=====================\n");

}

int main() {

    draw_map();

    char input = RIGHT;
    srand(time(NULL));

    Target target;
    Snake snake;

    
    MoveStatus st = none;
    while (1) {
        Sleep(snake.clock);

        if (_kbhit()) {
            input = _getch();
            if (input == -32) {
                input = _getch();
            }
        }
        
        st = snake.move(input);

        if (st == meet_target) {
            target.CreateNewTarget(snake.body);
            snake.speed_up();
        }
        else if (st == meet_edge || st == meet_snake) {
            gotoxy(6, 10);
            printf("Game Over!\n");
            break;
        }
        else if (st == none) {

        }
        else {

        }
    }
    system("pause");

    return 0;
}