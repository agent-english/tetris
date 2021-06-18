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
    //delete [] offset; //I need to find out if it is necessary. This proj should never have memory leak
}

void Shape_J::print(){
    attron(COLOR_PAIR(COLOR_J));
    Shape::print();
    attroff(COLOR_PAIR(COLOR_J));
    //delete [] offset; //I need to find out if it is necessary. This proj should never have memory leak
}

void Shape_O::print(){
    attron(COLOR_PAIR(COLOR_O));
    Shape::print();
    attroff(COLOR_PAIR(COLOR_O));
    //delete [] offset; //I need to find out if it is necessary. This proj should never have memory leak
}

void Shape_L::print(){
    attron(COLOR_PAIR(COLOR_L));
    Shape::print();
    attroff(COLOR_PAIR(COLOR_L));
    //delete [] offset; //I need to find out if it is necessary. This proj should never have memory leak
}

void Shape_Z::print(){
    attron(COLOR_PAIR(COLOR_Z));
    Shape::print();
    attroff(COLOR_PAIR(COLOR_Z));
    //delete [] offset; //I need to find out if it is necessary. This proj should never have memory leak
}

void Shape_T::print(){
    attron(COLOR_PAIR(COLOR_T));
    Shape::print();
    attroff(COLOR_PAIR(COLOR_T));
    //delete [] offset; //I need to find out if it is necessary. This proj should never have memory leak
}

void Shape_S::print(){
    attron(COLOR_PAIR(COLOR_S));
    Shape::print();
    attroff(COLOR_PAIR(COLOR_S));
    //delete [] offset; //I need to find out if it is necessary. This proj should never have memory leak
}
