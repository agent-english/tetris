#pragma once

#include <ncurses.h>
#include "coordinates.hpp"
#include "field.hpp"

#define SPEED SPEED_1

#define SPEED_1 0xFFFFF
#define SPEED_2 0xEFFFF
#define SPEED_3 0xDFFFF
#define SPEED_4 0xCFFFF
#define SPEED_5 0xBFFFF
#define SPEED_6 0xAFFFF
#define SPEED_7 0x9FFFF
#define SPEED_8 0x8FFFF
#define SPEED_9 0x7FFFF
#define SPEED_10 0x6FFFF

#define COLOR_I 2
#define COLOR_J 3
#define COLOR_O 4
#define COLOR_L 5
#define COLOR_Z 6
#define COLOR_T 7
#define COLOR_S 8

#define HORIZONTAL 1
#define VERTICAL 2
#define HORIZONTAL_LJT 3 //orientations for figures(L, J, T), which have 4 positions
#define VERTICAL_LJT 4

typedef unsigned char uint8;

class Shape{
public:
    explicit Shape(Field *field, uint8 size);
    virtual ~Shape();
    void init_offset(Position *offset);
    Position *get_offset();
    void set_offset(Position *offset);
    Position get_start_position();
    uint8 get_size();
    Position getPosition(uint8 index);

    void move_shape();
    bool out_of_boarders(int x, int y);
    bool is_settable(Position *offset);//возможно ненужная функция. удалить потом
    bool check_hit();

    virtual bool rotate();
    
    virtual void print() = 0;

private:
    uint8 *block_;//4
    uint8 size_;//4 
    Position startPosition_;
    Position *offset_; //4
    short int **matrix_; //it is a pointer to field's matrix
    bool is_hit_;
};

class Shape_I : public Shape{ //start position: horizontal
public:
    Shape_I(Field *field);  
    bool rotate();
    void print();
private:
    int colour_; // CYAN
    int orientation_;
};

class Shape_L : public Shape{
public:
    Shape_L(Field *field);
    bool rotate();
    void print();
private:
    int colour_;
    int orientation_;
};

class Shape_J : public Shape{
public:
    Shape_J(Field *field);
    bool rotate();
    void print();
private:
    int colour_;
    int orientation_;
};

class Shape_T : public Shape{
public:
    Shape_T(Field *field);
    bool rotate();
    void print();
private:
    int colour_;
    int orientation_;
};

class Shape_Z : public Shape{
public:
    Shape_Z(Field *field);
    bool rotate();
    void print();
private:
    int colour_;
    int orientation_;
};

class Shape_S : public Shape{
public:
    Shape_S(Field *field);
    bool rotate();
    void print();
private:
    int colour_;
    int orientation_;
};

class Shape_O : public Shape{
public:
    Shape_O(Field *field);
    void print();
private:
    int colour_;
};
