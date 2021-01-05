#ifndef _ENV_H
#define _ENV_H

#include "Snake.h"
#include "Target.h"

class Env {
private:
    Snake* m_pSnake;
    Target* m_pTarget;
    int m_clock;
public:
    
    Env() {
        m_pSnake = nullptr;
        m_pTarget = nullptr;
    }

    void Init();

    MoveStatus Move(int direction);
    void CreateNewTarget();
    int GetClock();
    void SpeedUp();
    void Sleep();
    ~Env() {
        delete m_pTarget;
        delete m_pSnake;
    }

};

#endif 
