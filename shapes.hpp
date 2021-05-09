#pragma once

#include <ncurses.h>
#include "coordinates.hpp"
#include "field.hpp"

typedef unsigned char uint8;

class Shape{
public:
    explicit Shape(uint8 size) : size_(size){
        block_ = new uint8[size_];
        position_ = new Position[size_];
        //I should never use virtual funcs int the constractors
    }
    virtual void print() = 0;
    void move();
    //нужно определиться с тем как отображать фигуры на игровом поле. Когда стоит помещать их в матрицу?
    //как вариант, сейчас предлагаю следующую схему: фигура вносится сразу в матрицу. Потом по мере погружения, когда 
    //фигура достигнет дна стакана объект фигура удаляется и создается новый
    
    //Но такой вариант не подойдет, если я хочу сделать фигуры разного цвета.
    //virtual void print_shape() = 0;
    void rotate(); //nope
    virtual ~Shape(){
        delete [] block_;
        delete [] position_;
    }
    //virtual bool can_rotate() = 0;
    //virtual void set_colour() = 0;
    //void changePosition(int8 direction);
    void set_block(uint8 block);
    void set_position(Position *position);
    uint8 get_size();
    void link_a_field(Field *field){
        field_ = field;
    }
private:
    uint8 *block_;//4
    uint8 size_;//4
    Position *position_;//4 
    Field *field_;    
    //virtual ~Shape();//деструктор размещен здесь для того, 
                       //чтобы автоматически не удалялся объект при выходе из функции

protected:
    //Shape();
};

class Shape_I : public Shape{
public:
    Shape_I() : Shape(4){ //вызывается конструктор Shape
        uint8 size = get_size();
        uint8 block = 1;
        Position *position = new Position[size];
        for(uint8 i = 0; i < size; i++){
            position[i].x = FIELD_SIZE_X / 2;
            position[i].y = i;
        }
        set_block(block);
        set_position(position);
        delete [] position;
    }  
    void rotate();
    bool can_rotate();
    void print();
private:
    int colour;
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
