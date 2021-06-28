#include <cstdlib>
#include "shapes.hpp"

void Shape::print(){
    uint size = get_size();
    Position *offset = new Position[size];
    offset = get_offset();
    Position start_position = get_start_position();
    for(uint i = 0; i < size; i++){
        move(start_position.y + offset[i].y, start_position.x - (offset[i].x * 2) - 1);
        addstr("II");
    }
}

void Shape_I::print(){
    attron(COLOR_PAIR(COLOR_I));
    Shape::print();
    attroff(COLOR_PAIR(COLOR_I));
}

void Shape_J::print(){
    attron(COLOR_PAIR(COLOR_J));
    Shape::print();
    attroff(COLOR_PAIR(COLOR_J));
}

void Shape_O::print(){
    attron(COLOR_PAIR(COLOR_O));
    Shape::print();
    attroff(COLOR_PAIR(COLOR_O));
}

void Shape_L::print(){
    attron(COLOR_PAIR(COLOR_L));
    Shape::print();
    attroff(COLOR_PAIR(COLOR_L));
}

void Shape_Z::print(){
    attron(COLOR_PAIR(COLOR_Z));
    Shape::print();
    attroff(COLOR_PAIR(COLOR_Z));
}

void Shape_T::print(){
    attron(COLOR_PAIR(COLOR_T));
    Shape::print();
    attroff(COLOR_PAIR(COLOR_T));
}

void Shape_S::print(){
    attron(COLOR_PAIR(COLOR_S));
    Shape::print();
    attroff(COLOR_PAIR(COLOR_S));
}
