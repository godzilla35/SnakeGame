#ifndef _TARGET_H_
#define _TARGET_H_

#include <vector>

#include "GameDefine.h"
#include "Funcs.h"

using namespace std;

class Target {
private:
    const char target_char = '#';
    int target_cnt, m_posX, m_posY;
public:
    
    Target();
    Target(int _x, int _y);
    void CreateNewTarget(const vector<pair<int, int>>& snake_body);
    bool IsTargetPos(int _x, int _y);
};


#endif