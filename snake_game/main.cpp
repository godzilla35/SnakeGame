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



void gotoxy(int x, int y) {
  COORD pos = {x, y};
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

class Target {
 public:
  int target_cnt, x, y;
  Target() { 
    target_cnt = 0;
    x = rand() % 50;
    y = rand() % 50;
  
    gotoxy(x, y);
    printf("★");
  }

  void CreateNewTarget(const vector<pair<int, int>>& snake_body) {
    target_cnt++;
    bool retry = true;
    while (retry) {
      x = rand() % 50;
      y = rand() % 50;

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

  void move(int direction) {
    if (body.size() == 0)
      return;

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

    // 마지막 몸 삭제
    gotoxy(body[body_len - 1].first, body[body_len - 1].second);
    printf(" ");
    
    for (int i = 1; i < body_len; i++) {
      body[i] = body[i - 1];
    }
    body[0] = top;

    // 대가리 그림
    gotoxy(body[0].first, body[0].second);
    printf("@");
  }

  void body_inc() {

  }
};



bool inc_snake_len = false;
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
        if (inc_snake_len == false) {
          // gotoxy(x, y);
          // printf(" ");
        } else {
          inc_snake_len = false;
        }
        snake.move(input);

      } else if (input == '1') {
        inc_snake_len = true;
        // break;
      }
    }
  }

  return 0;
}