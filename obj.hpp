#include <ncurses.h>
#include "coordinates.hpp"

#define FIELD_SIZE_X 20
#define FIELD_SIZE_Y 10

typedef unsigned char uint8;

class Shape{
public:
    void move(uint8 direction);
    bool set_shape();
    virtual void print_shape() = 0;
    void rotate(); //nope
    virtual bool can_rotate() = 0;
    //void changePosition(int8 direction);
    virtual ~Shape();
private:
    uint8 *block_;//4
    uint8 size_;//4
    Position *position_;//4     
protected:
    explicit Shape(uint8 *block, uint8 size, uint8 colour, Position *position);
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

class Field {
public:
    Field(); 
    int fill(Shape *shape);//return value - score
    void delete_line(short int num);
    void print();//boarders and matrix
private:
    int matrix[FIELD_SIZE_X][FIELD_SIZE_Y];
    char boarder;
    Position position_; 
};


class Score{
public:
    //eran_points
    //get_points - print current number of points
    //print
private:
    int points_;
    Position position;
};


//class Glass{





//};
