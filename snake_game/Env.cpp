#include "Env.h"
#include "Snake.h"
#include "Target.h"

void Env::Init() {
    int x, y;
    x = rand() % (MAX_WIDTH - 1) + 1;
    y = rand() % (MAX_HEIGHT - 1) + 1;
    m_pTarget = new Target(x, y);

    int s_x, s_y;

    do {
        s_x = rand() % (MAX_WIDTH - 1) + 1;
        s_y = rand() % (MAX_HEIGHT - 1) + 1;
    } while (s_x == x || s_y == y);

    m_pSnake = new Snake(s_x, s_y);
    m_clock = 1000;
}

MoveStatus Env::Move(int direction)
{
    int body_len = m_pSnake->GetSize();

    if (body_len == 0)
        return err;

    
    pair<int, int> top = m_pSnake->GetTop();
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
    if (m_pTarget->IsTargetPos(top.first, top.second)) 
    {
        m_pSnake->EatFood(top.first, top.second);
        return meet_target;
    }
    else if (m_pSnake->IsBody(top)) 
    {
        return meet_snake;
    }
    else if (m_pSnake->IsEdge(top)) 
    {
        return meet_edge;
    }
    else
    {
        m_pSnake->move(top.first, top.second);
        return none;
    }

}

void Env::CreateNewTarget()
{
    m_pTarget->CreateNewTarget(m_pSnake->body);
}

int Env::GetClock()
{
    return m_clock;
}

void Env::SpeedUp()
{
    // 최고 속도
    if (m_clock == 100) return;

    m_clock -= 100;
}