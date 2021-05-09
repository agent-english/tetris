#include <cstdlib>
#include <ctime>
#include "shapes.hpp"

bool Shape::settalbe(){ // this function checks if it is possible to set a shape
    for(uint i = 0; i < size_; i++){ 
        if(!(field_->fill(position_[i]))) return false;
    }
}

void Shape::move(Field *field){
    set_shape(field);
    field->print_field();
    /*switch(direction){
        case KEY_UP:
            y -= 1;
            break;
        case KEY_DOWN:
            y += 1;
            break;
        case KEY_LEFT:
            x -= 2;
            break;
        case KEY_RIGHT:
            x += 2;
            break;
        case 'q':
            break;
        }
    }*/
}

void Shape::set_block(uint8 block){
    for(uint8 i = 0; i < size_; i++){
        *(block_ + i) = block;
    }
}

void Shape::set_position(Position *position){
    for (uint8 i = 0; i < size_; i++){
        position_[i].x = position[i].x;
        position_[i].y = position[i].y;
    }
}
uint8 Shape::get_size(){
    return size_;
}

void Shape_I::print(Field *field){

}