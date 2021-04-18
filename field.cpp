#include "field.hpp"
#include "coordinates.hpp"
#include <ncurses.h>

Field::Field(){
    matrix = new short int[FIELD_SIZE_Y];
    for(int i = 0; i < FIELD_SIZE_X; matix[i++] = 0);//matrix init
    vertical_boarder_ = '|';

    int centre_x = getmaxx(stdscr) / 2; 
    int centre_y = getmaxy(stdscr) / 2;
    position_.x = centre_x - FIELD_SIZE_X;
    position_.y = centre_y - FIELD_SIZE_Y;
}

Field::print_field(){
    Position temp = position_;
    temp.x -= 2;
    temp.y -= 1;
    move(temp.y, temp.x);
    for(int i = FIELD_SIZE_Y; i >= 0; i--){
        addch(vertical_boarder_);
        for(int j = FIELD_SIZE_X; j >= 0; j--){
            temp.x += 2;
            move(temp.y, temp.x);
            addstr("CC");
        }
        addch(vertical_boarder_);
        temp.x -= FIELD_SIZE_X * 2;
        temp.y += 1;
        move(temp.y, temp.x);
    }
    temp.x -= 2;
    for(int i = 0; i < FIELD_SIZE_X + 2; i++){
        addstr("‾‾")
        temp.x += i * 2;
        move(temp.y, temp.x);
    }
}

