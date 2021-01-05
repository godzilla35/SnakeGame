#include "GameDefine.h"
#include "Funcs.h"

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void gotoxy_draw(int x, int y, char c) {
    gotoxy(x, y);
    printf("%c", c);
}

void draw_map()
{
    char upper_edge[256] = "";
    char side_edge[256] = "";

    for (int i = 0; i < MAX_WIDTH + 1; i++)
    {
        upper_edge[i] = '=';
    }


    for (int i = 0; i < MAX_WIDTH + 1; i++)
    {
        side_edge[i] = ' ';
    }
    side_edge[0] = '=';
    side_edge[MAX_WIDTH] = '=';

    gotoxy(0, 0);
    printf("%s\n", upper_edge);
    for (int i = 0; i < MAX_HEIGHT; i++) printf("%s\n", side_edge);
    printf("%s\n", upper_edge);

}