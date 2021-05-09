#pragma once

#include "coordinates.hpp"

//struct Position;

struct Field{
public:
    Field();
    bool fill(Position *position);
    void print_currentShape(Shape currentShape);
    void delete_line();
    void print_field(); // with boarders

private:
    short int *matrix;
    char vertical_boarder_;
    char horizontal_boarder_;
    Position position_;
};

