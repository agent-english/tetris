#pragma once

#include "field.hpp"
#include "shapes.hpp"

#define SPEED SPEED_1

#define SPEED_1 0xFFFFF
#define SPEED_2 0xDFFFF
#define SPEED_3 0xBFFFF
#define SPEED_4 0x9FFFF
#define SPEED_5 0x7FFFF
#define SPEED_6 0x5FFFF
#define SPEED_7 0x3FFFF
#define SPEED_8 0x1FFFF

class Game{
public:
    Game();
    int init();
    int mainloop();
    void clock();
    void setScore(Field *field);
    int getScore();
    void printScore();
    void printGameOver();
private:
    int score_;
};

Game::Game(){
    score = 0;
}

void moveShape(Game *game, Field *field, Shape *currentShape);
