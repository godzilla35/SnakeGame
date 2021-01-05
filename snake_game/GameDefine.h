#ifndef _GAME_DEFINE_H
#define _GAME_DEFINE_H

enum MoveStatus
{
    none,
    err,
    meet_target,
    meet_edge,
    meet_snake
};


#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80


#define MAX_WIDTH 40
#define MAX_HEIGHT 20

#endif