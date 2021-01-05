#include <vector>

#include "GameDefine.h"
#include "Snake.h"
#include "Funcs.h"

using namespace std;


/*
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
            pos.first == MAX_WIDTH ||
            pos.second == 0 ||
            pos.second == MAX_HEIGHT);
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

    Snake(int _x, int _y) {
        body.push_back(make_pair(_x, _y));
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
            if (top.first < MAX_WIDTH)
                top.first++;
            break;
        case UP:
            if (top.second > 0)
                top.second--;
            break;
        case DOWN:
            if (top.second < MAX_HEIGHT)
                top.second++;
            break;
        }

        // 음식을 먹으면
        if (IsTarget(top)) {
            gotoxy_draw(top.first, top.second, ' ');

            body.push_back(body.back());
            for (int i = body.size() - 1; i > 0; i--) {
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
*/


bool Snake::IsBody(pair<int, int>& pos)
{
    for (auto p : body) {
        if (pos.first == p.first && pos.second == p.second) return true;
    }
    return false;
}

bool Snake::IsEdge(pair<int, int>& pos)
{
    return (pos.first == 0 ||
            pos.first == MAX_WIDTH ||
            pos.second == 0 ||
            pos.second == MAX_HEIGHT);
}

Snake::Snake()
{
    body.push_back(make_pair(1, 1));
    direction = RIGHT;
    gotoxy_draw(body[0].first, body[0].second, '@');
}

Snake::Snake(int _x, int _y)
{
    body.push_back(make_pair(_x, _y));
    direction = RIGHT;
    gotoxy_draw(body[0].first, body[0].second, '@');
}


int Snake::GetSize()
{
    return body.size();
}

const pair<int, int>& Snake::GetTop()
{
    return body.front();
}

void Snake::move(int next_x, int next_y)
{
    int body_len = body.size();

    // 마지막 몸 삭제
    gotoxy_draw(body[body_len - 1].first, body[body_len - 1].second, ' ');

    for (int i = body.size() - 1; i > 0; i--) 
    {
        body[i] = body[i - 1];
    }

    body[0] = make_pair(next_x, next_y);
    gotoxy_draw(body[0].first, body[0].second, '@');

}

void Snake::EatFood(int food_x, int food_y)
{
    // 음식 삭제
    gotoxy_draw(food_x, food_y, ' ');

    // 뱀의 꼬리에 하나를 추가
    body.push_back(body.back());

    // 뱀의 각 노드를 한칸씩 뒤로 
    for (int i = body.size() - 1; i > 0; i--) {
        body[i] = body[i - 1];
    }
    
    // 음식의 위치에 뱀의 머리 삽입 
    body[0] = make_pair(food_x, food_y);

    // 머리 그림
    gotoxy_draw(body[0].first, body[0].second, '@');
}
