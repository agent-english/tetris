#pragma once

#include "field.hpp"
#include "shapes.hpp"

class Game{
public:
    Game(){
        score_ = 0;
    }
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

void moveShape(Game *game, Field *field, Shape *currentShape);