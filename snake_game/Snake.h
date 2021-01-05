#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <vector>

#include "GameDefine.h"

using namespace std;

class Snake {

private:


public:


    int direction;
    
    vector<pair<int, int>> body;
    Snake();

    Snake(int _x, int _y);

    
    int GetSize();
    const pair<int, int>& GetTop();

    void move(int next_x, int next_y);
    void EatFood(int food_x, int food_y);
    bool IsBody(pair<int, int>& pos);
    bool IsEdge(pair<int, int>& pos);


};

#endif