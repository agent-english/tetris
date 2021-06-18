#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "shapes.hpp"

static unsigned int counter = 0;

extern bool gameOver;

void Shape::move_shape(){
    int direction = 0;

    while(true){            //clock
        if(counter++ > SPEED){
            counter = 0;
            for(uint8 i = 0; i < size_; i++){
                offset_[i].y += 1;
            }
            break;
        }
        direction = getch();
        if (direction != -1) break;
    }

    int temp_y = 0;
    int temp_x = 0;
    switch(direction){ // select the direction
        case KEY_UP:
            rotate();
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
    if((temp_x || temp_y) && !out_of_boarders(temp_x, temp_y)) { //checks if some changes happend and they are in the field area
        Position *temp = new Position[size_];
        for(uint8 i = 0; i < size_; i++){
            temp[i].x = offset_[i].x + temp_x;
            temp[i].y = offset_[i].y + temp_y;
        }
            for(uint8 i = 0; i < size_; i++){
                offset_[i].x = temp[i].x;
                offset_[i].y = temp[i].y;
            }
    }
}

uint8 Shape::get_size(){
    return size_;
}

Position Shape::getPosition(uint8 index){
    return offset_[index];
}

void Shape::init_offset(Position *offset){
    for(uint8 i = 0; i < size_; i++){
        offset_[i].x = offset[i].x;
        offset_[i].y = offset[i].y;
    }
}


bool Shape::out_of_boarders(int x, int y){
    int temp_x, temp_y;
    for(uint i = 0; i < size_; i++){
        temp_y = offset_[i].y + y;
        temp_x = offset_[i].x + x;
        if(temp_y > FIELD_SIZE_Y - 1 || temp_y < 0 || temp_x < 0 || temp_x > FIELD_SIZE_X - 1) return true;
    }
    return false;
}

bool Shape::check_hit(){//this func checks the hit while shape is moving and when we need to create a new shape
    if(is_hit_) return true;
    for(uint8 i = 0; i < size_; i++){
        if(offset_[i].y + 1 >= FIELD_SIZE_Y){
            is_hit_ = true;
            return is_hit_;
        }
        if((*(*(matrix_) + offset_[i].y + 1)) & (1 << offset_[i].x)){ 
            is_hit_ = true;
            return is_hit_;
        }
    }
    return false;
}

Position * Shape::get_offset(){
    return offset_;
}

void Shape::set_offset(Position *offset){
    for(int i = 0; i < size_; i++){
        offset_[i] = offset[i];
    }
}

bool Shape::is_settable(Position *offset){//this func works incorrect. do something with it
    bool result = true;
    for(int i = 0; i < size_; i++){
        if((*(*(matrix_) + (offset[i].y))) & (1 << offset[i].x)){
            result = false;
            break;
        }
    }
    return result;
}

Position Shape::get_start_position(){
    return startPosition_;
}

bool Shape::rotate(){
    //__nop();
    return false;
}

bool Shape_I::rotate(){
    bool result = false;
    Position tempPosition[4];
    for(int i = 0; i < 4; i++){
        tempPosition[i] = getPosition(i);
    }
    if(orientation_ == HORIZONTAL){
        tempPosition[0].x -= 2;
        tempPosition[0].y -= 2;
        tempPosition[1].x -= 1;
        tempPosition[1].y -= 1;
        tempPosition[3].x += 1;
        tempPosition[3].y += 1;
        if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = VERTICAL;
                result = true;
        }
    }
    else{
        tempPosition[0].x += 2;
        tempPosition[0].y += 2;
        tempPosition[1].x += 1;
        tempPosition[1].y += 1;
        tempPosition[3].x -= 1;
        tempPosition[3].y -= 1;
        if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = HORIZONTAL;
                result = true;
        }
    }
    return result;
}

bool Shape_L::rotate(){
    bool result = false;
    Position tempPosition[4];
    for(int i = 0; i < 4; i++){
        tempPosition[i] = getPosition(i);
    }
    switch(orientation_){
        case HORIZONTAL:{
            tempPosition[0].x += 1;
            tempPosition[0].y += 1;
            tempPosition[2].x -= 1;
            tempPosition[2].y -= 1;
            tempPosition[3].y -= 2;
            if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = VERTICAL;
                result = true;
            }
            break;
        }
        case VERTICAL:{
            tempPosition[0].x += 1;
            tempPosition[0].y -= 1;
            tempPosition[2].x -= 1;
            tempPosition[2].y += 1;
            tempPosition[3].x -= 2;
            if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = HORIZONTAL_LJT;
                result = true;
            }
            break;
        }
        case HORIZONTAL_LJT:{
            tempPosition[0].x -= 1;
            tempPosition[0].y -= 1;
            tempPosition[2].x += 1;
            tempPosition[2].y += 1;
            tempPosition[3].y += 2;
            if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = VERTICAL_LJT;
                result = true;
            }
            break;
        }
        case VERTICAL_LJT:{
            tempPosition[0].x -= 1;
            tempPosition[0].y += 1;
            tempPosition[2].x += 1;
            tempPosition[2].y -= 1;
            tempPosition[3].x += 2;
            if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = HORIZONTAL;
                result = true;
            }
            break;
        }
    };
    return result;
}

bool Shape_J::rotate(){
    bool result = false;
    Position tempPosition[4];
    for(int i = 0; i < 4; i++){
        tempPosition[i] = getPosition(i);
    }
    switch(orientation_){
        case HORIZONTAL:{
            tempPosition[0].x -= 1;
            tempPosition[0].y -= 1;
            tempPosition[2].x += 1;
            tempPosition[2].y += 1;
            tempPosition[3].x += 2;
            if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = VERTICAL;
                result = true;
            }
            break;
        }
        case VERTICAL:{
            tempPosition[0].x -= 1;
            tempPosition[0].y += 1;
            tempPosition[2].x += 1;
            tempPosition[2].y -= 1;
            tempPosition[3].y -= 2;
            if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = HORIZONTAL_LJT;
                result = true;
            }
            break;
        }
        case HORIZONTAL_LJT:{
            tempPosition[0].x += 1;
            tempPosition[0].y += 1;
            tempPosition[2].x -= 1;
            tempPosition[2].y -= 1;
            tempPosition[3].x -= 2;
            if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = VERTICAL_LJT;
                result = true;
            }
            break;
        }
        case VERTICAL_LJT:{
            tempPosition[0].x += 1;
            tempPosition[0].y -= 1;
            tempPosition[2].x -= 1;
            tempPosition[2].y += 1;
            tempPosition[3].y += 2;
            if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = HORIZONTAL;
                result = true;
            }
            break;
        }
    };
    return result;
}

bool Shape_T::rotate(){
    bool result = false;
    Position tempPosition[4];
    for(int i = 0; i < 4; i++){
        tempPosition[i] = getPosition(i);
    }
    switch(orientation_){
        case HORIZONTAL:{
            tempPosition[0].x -= 1;
            tempPosition[0].y -= 1;
            tempPosition[2].x += 1;
            tempPosition[2].y += 1;
            tempPosition[3].x += 1;
            tempPosition[3].y -= 1;
            if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = VERTICAL;
                result = true;
            }
            break;
        }
        case VERTICAL:{
            tempPosition[0].x -= 1;
            tempPosition[0].y += 1;
            tempPosition[2].x += 1;
            tempPosition[2].y -= 1;
            tempPosition[3].x -= 1;
            tempPosition[3].y -= 1;
            if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = HORIZONTAL_LJT;
                result = true;
            }
            break;
        }
        case HORIZONTAL_LJT:{
            tempPosition[0].x += 1;
            tempPosition[0].y += 1;
            tempPosition[2].x -= 1;
            tempPosition[2].y -= 1;
            tempPosition[3].x -= 1;
            tempPosition[3].y += 1;
            if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = VERTICAL_LJT;
                result = true;
            }
            break;
        }
        case VERTICAL_LJT:{
            tempPosition[0].x += 1;
            tempPosition[0].y -= 1;
            tempPosition[2].x -= 1;
            tempPosition[2].y += 1;
            tempPosition[3].x += 1;
            tempPosition[3].y += 1;
            if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = HORIZONTAL;
                result = true;
            }
            break;
        }
    };
    return result;
}

bool Shape_Z::rotate(){
    bool result = false;
    Position tempPosition[4];
    for(int i = 0; i < 4; i++){
        tempPosition[i] = getPosition(i);
    }
    if(orientation_ == HORIZONTAL){
        tempPosition[0].x -= 1;
        tempPosition[0].y -= 1;
        tempPosition[2].x += 1;
        tempPosition[2].y -= 1;
        tempPosition[3].x += 2;
        if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = VERTICAL;
                result = true;
        }
    }
    else{
        tempPosition[0].x += 1;
        tempPosition[0].y += 1;
        tempPosition[2].x -= 1;
        tempPosition[2].y += 1;
        tempPosition[3].x -= 2;
        if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = HORIZONTAL;
                result = true;
        }
    }
    return result;
}

bool Shape_S::rotate(){
    bool result = false;
    Position tempPosition[4];
    for(int i = 0; i < 4; i++){
        tempPosition[i] = getPosition(i);
    }
    if(orientation_ == HORIZONTAL){
        tempPosition[0].x -= 1;
        tempPosition[0].y -= 1;
        tempPosition[2].x -= 1;
        tempPosition[2].y += 1;
        tempPosition[3].y += 2;
        if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = VERTICAL;
                result = true;
        }
    }
    else{
        tempPosition[0].x += 1;
        tempPosition[0].y += 1;
        tempPosition[2].x += 1;
        tempPosition[2].y -= 1;
        tempPosition[3].y -= 2;
        if (is_settable(tempPosition)){
                set_offset(tempPosition);
                orientation_ = HORIZONTAL;
                result = true;
        }
    }
    return result;
}

