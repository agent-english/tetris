#pragma once

#define CENTRE_X getmaxx(stdscr) / 2
#define CENTRE_Y getmaxy(stdscr) / 2

#define FIELD_SIZE_X 10
#define FIELD_SIZE_Y 20

struct Position{
    int x;
    int y;
};
