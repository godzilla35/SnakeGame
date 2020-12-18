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
#define MAX_EDGE 100

int cur_target_x, cur_target_y;

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
        cur_target_x = x = rand() % 50;
        cur_target_y = y = rand() % 50;



        gotoxy(x, y);
        printf("★");
    }

    void CreateNewTarget(const vector<pair<int, int>>& snake_body) {
        target_cnt++;
        bool retry = true;
        while (retry) {
            cur_target_x = x = rand() % 50;
            cur_target_y = y = rand() % 50;

            retry = false;
            for (auto p : snake_body) {
                if (p.first == x && p.second == y) {
                    retry = true;
                    break;
                }
            }
        }

        gotoxy(x, y);
        printf("★");
    }
};

class Snake {
public:
    vector<pair<int, int>> body;
    Snake() { body.push_back(make_pair(1, 1)); }

    void draw() {
        for (auto i : body) {
            gotoxy(i.first, i.second);
            printf("@");
        }
    }

    bool move(int direction) {
        if (body.size() == 0)
            return false;

        bool ret = false;
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
        if (top.first == cur_target_x && top.second == cur_target_y) {
            gotoxy_draw(top.first, top.second, ' ');
            
            body.push_back(body.back());
            for (int i = body.size() - 1; i > 0 ; i--) {
                body[i] = body[i - 1];
            }

            ret = true;

        }
        else {
            // 마지막 몸 삭제
            gotoxy_draw(body[body_len - 1].first, body[body_len - 1].second, ' ');
            

            for (int i = body.size() - 1; i > 0; i--) {
                body[i] = body[i - 1];
            }
        }

        body[0] = top;
        gotoxy_draw(body[0].first, body[0].second, '@');
        

        return ret;
    }

    void body_inc() {
        
    }
};


int main() {
    char input = 0;
    srand(time(NULL));

    Target target;
    Snake snake;


    snake.draw();

    while (1) {
        if (_kbhit()) {
            input = _getch();
            if (input == -32) {
                input = _getch();
               
                if (snake.move(input)) {
                    target.CreateNewTarget(snake.body);
                }

            }
        }
    }

    return 0;
}