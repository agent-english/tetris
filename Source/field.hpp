#pragma once

#include "coordinates.hpp"

#define FULL_LINE 0b1111111111

struct Field{
public:
    Field();
    void fill(Position *position);
    int checkLines();
    void delete_line(int line);
    void print_field();
    Position get_position();
    short int **get_matrix();
private:
    short int *matrix_;
    char vertical_boarder_;
    char horizontal_boarder_;
    Position position_;
};
