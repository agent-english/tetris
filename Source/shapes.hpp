#pragma once

#include <ncurses.h>
#include "coordinates.hpp"
#include "field.hpp"

#define COLOR_I 2 // CYAN
#define COLOR_L 3 // BLUE
#define COLOR_J 4 // YELLOW
#define COLOR_T 5 // WHITE
#define COLOR_Z 6 // RED
#define COLOR_S 7 // MAGENTA
#define COLOR_O 8 // GREEN

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
    bool is_settable(Position *offset);
    bool is_settable(); // for checking the end of the game
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
    int colour_;
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
