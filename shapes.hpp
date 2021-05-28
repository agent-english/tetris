#pragma once

#include <ncurses.h>
#include "coordinates.hpp"
#include "field.hpp"

#define COLOR_I 2
#define COLOR_J 3
#define COLOR_O 4
#define COLOR_L 5
#define COLOR_Z 6
#define COLOR_T 7
#define COLOR_S 8

typedef unsigned char uint8;

class Shape{
public:
    explicit Shape(Field *field, uint8 size) : size_(size){
        block_ = new uint8[size_];
        startPosition_.x = CENTRE_X + FIELD_SIZE_X;
        startPosition_.y = CENTRE_Y - FIELD_SIZE_Y / 2;
        //move(startPosition_.y,startPosition_.x);
        //addch('s');
        offset_ = new Position[size_];
        matrix_ = field->get_matrix();
        //I should never use virtual funcs int the constractors
    }
    void init_offset(Position *offset);
    Position *get_offset();
    Position get_start_position();
    uint8 get_size();
    virtual ~Shape(){
        if(this != NULL){
            delete [] block_;
            delete [] offset_;
        }
    }

    void move_shape();
    bool is_settable(Position *offset);
    bool check_hit();
    virtual void print() = 0;

private:
    uint8 *block_;//4
    uint8 size_;//4 
    Position startPosition_;
    Position *offset_; //4
    short int **matrix_; //it is a pointer to field's matrix
};

class Shape_I : public Shape{ //start position: horizontal
public:
    Shape_I(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        for(uint8 i = 0; i < size; i++){
            offset[i].x = 6 - i;
            offset[i].y = 0;
        }
        init_offset(offset);
        delete [] offset;
        colour_ = 1;
    }  
    void rotate();
    bool can_rotate();
    void print();
private:
    int colour_; // CYAN
};

class Shape_J : public Shape{
public:
    Shape_J(); //вызывается конструктор Shape
    void rotate();
    bool can_rotate();

private:
    int colour;
};

class Shape_O : public Shape{
public:
    Shape_O(); //вызывается конструктор Shape
    void rotate();
    bool can_rotate();

private:
    int colour;
};

class Shape_L : public Shape{
public:
    Shape_L(); //вызывается конструктор Shape
    void rotate();
    bool can_rotate();

private:
    int colour;
};

class Shape_Z : public Shape{
public:
    Shape_Z(); //вызывается конструктор Shape
    void rotate();
    bool can_rotate();

private:
    int colour;
};

class Shape_T : public Shape{
public:
    Shape_T(); //вызывается конструктор Shape
    void rotate();
    bool can_rotate();

private:
    int colour;
};

class Shape_S : public Shape{
public:
    Shape_S(); //вызывается конструктор Shape
    void rotate();
    bool can_rotate();

private:
    int colour;
};
