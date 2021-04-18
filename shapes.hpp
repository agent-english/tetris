#pragma once

#include <ncurses.h>
#include "coordinates.hpp"
#include "field.hpp"

typedef unsigned char uint8;

class Shape{
public:
    void move(int direction); //key_up, etc
    bool set_shape();
    virtual void print_shape() = 0;
    void rotate(); //nope
    virtual bool can_rotate() = 0;
    virtual void set_colour() = 0;
    //void changePosition(int8 direction);
    virtual ~Shape();
private:
    uint8 *block_;//4
    uint8 size_;//4
    Position *position_;//4     
protected:
    explicit Shape(uint8 *block, uint8 size, Position *position) : block_(block), size_(size){
        for(uint8 i = 0; i < size; i++){
            position_ = new Position[size_];
            position_[i].x = position[i].x;
            position_[i].y = position[i].y;
        }
        //set_colour(); //I should never use virtual funcs int the constractors
    }
};

class Shape_J : public Shape{
public:
    Shape_J(); //вызывается конструктор Shape
    void rotate();
    bool can_rotate();

private:
    int colour;
};

class Shape_I : public Shape{
public:
    Shape_I(); //вызывается конструктор Shape
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
