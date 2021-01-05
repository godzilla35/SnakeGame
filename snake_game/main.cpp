#include <Windows.h>
#include <conio.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include <queue>
#include <vector>

#include "GameDefine.h"
#include "Funcs.h"
#include "Env.h"


using namespace std;

int cur_target_x, cur_target_y;

/*
class Target {
private:
    const char target_char = '#';
public:
    int target_cnt, x, y;
    Target() {
        target_cnt = 0;
        cur_target_x = x = rand() % (MAX_WIDTH - 1) + 1;
        cur_target_y = y = rand() % (MAX_HEIGHT - 1) + 1;

        gotoxy_draw(x, y, target_char);
    }

    Target(int _x, int _y) {
        target_cnt = 0;
        x = _x;
        y = _y;
        gotoxy_draw(x, y, target_char);
    }

    void CreateNewTarget(const vector<pair<int, int>>& snake_body) {
        target_cnt++;
        bool retry = true;
        while (retry) {
            cur_target_x = x = rand() % (MAX_WIDTH - 1) + 1;
            cur_target_y = y = rand() % (MAX_HEIGHT - 1) + 1;

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

*/





void Init() {

}

int main() {

    draw_map();

    char input = RIGHT;
    srand(time(NULL));

    Env game;

    game.Init();

    MoveStatus st = none;
    while (1) {
        Sleep(game.GetClock());

        if (_kbhit()) {
            input = _getch();
            if (input == -32) {
                input = _getch();
            }
        }
        
        st = game.Move(input);

        if (st == meet_target) {
            game.CreateNewTarget();
            game.SpeedUp();
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