#pragma once

#define FIELD_SIZE_X 20
#define FIELD_SIZE_Y 10

struct Position;

struct Field{
public:
    void init_field();
    void fill();
    void delete_line();
    void print_field(); // with boarders
    void pritn_boarders();

private:
    Field(){
        init_field();
    }

    short int *matrix;
    char vertical_boarder_;
    char horizontal_boarder_;
    Position position_;
};

