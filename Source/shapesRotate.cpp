#include "shapes.hpp"
#include "coordinates.hpp"

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

