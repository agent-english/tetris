#pragma once

#include "coordinates.hpp"

#define FIELD_SIZE_X 10
#define FIELD_SIZE_Y 20

//struct Position;

struct Field{
public:
    Field();
    void fill();
    void delete_line();
    void print_field(); // with boarders
    void pritn_boarders();

private:
    short int *matrix;
    char vertical_boarder_;
    char horizontal_boarder_;
    Position position_;
};

