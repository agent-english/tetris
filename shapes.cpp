#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "shapes.hpp"

extern bool gameOver;

uint8 Shape::get_size(){
    return size_;
}

void Shape::init_offset(Position *offset){
    for(uint8 i = 0; i < size_; i++){
        offset_[i].x = offset[i].x;
        offset_[i].y = offset[i].y;
    }
}
void Shape::move_shape(){
    int direction = getch();//I'm not sure what exectly this func returns. maybe if there is no cathced char, it returns -1
    int temp_y = 0;
    int temp_x = 0;
    switch(direction){ // select the direction
        case KEY_UP:
            temp_y -= 1;
            break;
        case KEY_DOWN:
            temp_y += 1;
            break;
        case KEY_LEFT:
            temp_x += 1;
            break;
        case KEY_RIGHT:
            temp_x -= 1;
            break;
        case 'q':
            gameOver = true;
            break;
        default:
            break;
        };
    if(temp_x || temp_y){ //checks if some changes happend
        Position *temp = new Position[size_];
        for(uint i = 0; i < size_; i++){
            temp[i].x = offset_[i].x + temp_x;
            temp[i].y = offset_[i].y + temp_y;
        }
        //if(is_settable(temp)){//checks if the movement is possible and set new offset values
            for(uint i = 0; i < size_; i++){
                offset_[i].x = temp[i].x;
                offset_[i].y = temp[i].y;
                //sleep(5);
            }
        //  }
    }
}

bool Shape::is_settable(Position *offset){//this func works incorrect. do something with it
    bool result = true;
    for(int i = 0; i < size_; i++){
        result = *matrix_[offset[i].y] && 1 << offset_[i].x;
        if(!result) {
            return result;
        }
    }
    return result;
}

bool Shape::check_hit(){
    for(uint8 i; i < size_; i++){
        if((matrix_[offset_[i].y + 1]) && (1 << offset_[i].x)) return true;
    }
    return false;
}

Position * Shape::get_offset(){
    return offset_;
}
Position Shape::get_start_position(){
    return startPosition_;
}

void Shape_I::print(){
    attron(COLOR_PAIR(COLOR_I));
    uint size = get_size();
    Position *offset = new Position[size];
    offset = get_offset();
    Position start_position = get_start_position();
    for(uint i = 0; i < size; i++){
        move(start_position.y + offset[i].y, start_position.x - (offset[i].x * 2) - 1);
        addstr("II");
    }
    attroff(COLOR_PAIR(COLOR_I));
    //delete [] offset; //I need to find out if it is necessary. This proj should never have memory leak
}
