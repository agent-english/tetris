#include "field.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <iostream>

using namespace std;

Field::Field(){
    matrix_ = new short int[FIELD_SIZE_Y];
    for(int i = 0; i < FIELD_SIZE_X; matrix_[i++] = 0);//matrix init
    vertical_boarder_ = '|';
    horizontal_boarder_ = '/';

    /* int centre_x = getmaxx(stdscr) / 2; */ 
    /* int centre_y = getmaxy(stdscr) / 2; */
    Position temp;
    temp.x = CENTRE_X - FIELD_SIZE_X;
    temp.y = CENTRE_Y - (FIELD_SIZE_Y / 2);
    position_ = temp;
}

void Field::fill(Position *position){
    for(int i = 0; i < 4; i++){
        matrix_[position[i].y] |= 1 << position[i].x;
    }
}

short int ** Field::get_matrix(){  
    return &matrix_;
}

void Field::print_field(){
    //init_pair(1, COLOR_BLACK, COLOR_WHITE); /* create foreground / background combination */
    //init_pair(2, COLOR_BLUE, COLOR_BLUE);
    
    Position temp = position_;

    for(int i = 0; i < FIELD_SIZE_Y; i++, temp.y++){
        move(temp.y, temp.x);
        attron(COLOR_PAIR(1));
        addch(vertical_boarder_);
        temp.x += 1;
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(1));
        for(int j = FIELD_SIZE_X - 1; j >= 0; j--){
            if(*(matrix_ + i) & (0x1 << j)){
                addstr("oo"); // some temp value. i will put matrix here
            }
            temp.x += 2;
            move(temp.y, temp.x);
        }
        attron(COLOR_PAIR(1));
        addch(vertical_boarder_);
        temp.x -= FIELD_SIZE_X * 2 + 1;
        move(temp.y, temp.x);
    } 
    //temp.y++;
    for(int j = (FIELD_SIZE_X  * 2) + 2; j > 0; j--){
        move(temp.y, temp.x);
        addch(horizontal_boarder_); // some temp value. i will put matrix here
        temp.x += 1;
    }
}

Position Field::get_position(){
    return position_;
}

int Field::checkLines(){
    int result = 0;
    for(int i = FIELD_SIZE_Y - 1; i >= 0; i--){
        if (matrix_[i] == 0b1111111111){
            result++;
            delete_line(i);
            i++;
        }
    }
    return result;
}

void Field::delete_line(int line){
    for (uint8_t i = line; i > 0; i--){
        matrix_[i] = matrix_[i - 1];
    }
}