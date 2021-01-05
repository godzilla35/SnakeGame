
#include "Target.h"

/*
class Target {
private:
    const char target_char = '#';
    int target_cnt, m_posX, m_posY;

public:
    
    Target() {
        target_cnt = 0;
        m_posX = rand() % (MAX_WIDTH - 1) + 1;
        m_posY = rand() % (MAX_HEIGHT - 1) + 1;

        gotoxy_draw(m_posX, m_posY, target_char);
    }

    Target(int _x, int _y) {
        target_cnt = 0;
        m_posX = _x;
        m_posY = _y;
        gotoxy_draw(x, y, target_char);
    }

    void CreateNewTarget(const vector<pair<int, int>>& snake_body) {
        target_cnt++;
        bool retry = true;
        while (retry) {
            m_posX = rand() % (MAX_WIDTH - 1) + 1;
            m_posY = rand() % (MAX_HEIGHT - 1) + 1;

            retry = false;
            for (auto p : snake_body) {
                if (p.first == m_posX && p.second == m_posY) {
                    retry = true;
                    break;
                }
            }
        }

        gotoxy_draw(m_posX, m_posY, target_char);
    }

    IsTarget(int _x, int _y);
};
*/

Target::Target()
{
    target_cnt = 0;
    m_posX = rand() % (MAX_WIDTH - 1) + 1;
    m_posY = rand() % (MAX_HEIGHT - 1) + 1;

    gotoxy_draw(m_posX, m_posY, target_char);
}

Target::Target(int _x, int _y)
{
    target_cnt = 0;
    m_posX = _x;
    m_posY = _y;
    gotoxy_draw(m_posX, m_posY, target_char);
}

void Target::CreateNewTarget(const vector<pair<int, int>>& snake_body)
{
    target_cnt++;
    bool retry = true;
    while (retry) {
        m_posX = rand() % (MAX_WIDTH - 1) + 1;
        m_posY = rand() % (MAX_HEIGHT - 1) + 1;

        retry = false;
        for (auto p : snake_body) {
            if (p.first == m_posX && p.second == m_posY) {
                retry = true;
                break;
            }
        }
    }

    gotoxy_draw(m_posX, m_posY, target_char);
}

bool Target::IsTargetPos(int _x, int _y)
{
    return (_x == m_posX && _y == m_posY);
}
