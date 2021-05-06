#include "field.hpp"
#include "coordinates.hpp"
#include <ncurses.h>
#include <unistd.h>
#include <iostream>
using namespace std;

Field::Field(){
    matrix = new short int[FIELD_SIZE_Y];
    for(int i = 0; i < FIELD_SIZE_X; matrix[i++] = 0);//matrix init
    vertical_boarder_ = '|';

    int centre_x = getmaxx(stdscr) / 2; 
    int centre_y = getmaxy(stdscr) / 2;
    position_.x = centre_x - FIELD_SIZE_X;
    position_.y = centre_y - (FIELD_SIZE_Y / 2);
}

void Field::print_field(){
    init_pair(1, COLOR_BLACK, COLOR_WHITE); /* create foreground / background combination */
    init_pair(2, COLOR_BLUE, COLOR_BLUE);
    
    Position temp = position_;

    for(int i = 0; i < FIELD_SIZE_Y; i++, temp.y++){
        move(temp.y, temp.x);
        attron(COLOR_PAIR(1));
        addch(vertical_boarder_);
        temp.x += 1;
        attroff(COLOR_PAIR(1));
        //attron(COLOR_PAIR(2));
        for(int j = FIELD_SIZE_X - 1; j >= 0; j--){
            if(*(matrix + i) && (0x1 << j)) addstr("Co"); // some temp value. i will put matrix here
            //addstr("Co");
            temp.x += 2;
            move(temp.y, temp.x);
        }
        attron(COLOR_PAIR(1));
        addch(vertical_boarder_);
        temp.x -= FIELD_SIZE_X * 2 + 1;
        move(temp.y, temp.x);
    } 
    //temp.y++;
    for(int j = FIELD_SIZE_X + 1; j > 0; j--){
        move(temp.y, temp.x);
        addstr("//"); // some temp value. i will put matrix here
        temp.x += 2;
    }

}

