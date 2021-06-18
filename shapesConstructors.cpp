#include "shapes.hpp"

Shape::Shape(Field *field, uint8 size) : size_(size){
        block_ = new uint8[size_];
        startPosition_.x = CENTRE_X + FIELD_SIZE_X;
        startPosition_.y = CENTRE_Y - FIELD_SIZE_Y / 2;
        offset_ = new Position[size_];
        matrix_ = field->get_matrix();
        is_hit_ = false;
        //I should never use virtual funcs int the constractors
}

Shape::~Shape(){
        if(this != NULL){
            delete [] block_;
            delete [] offset_;
            //this = NULL;
        }
    }

Shape_I::Shape_I(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        for(uint8 i = 0; i < size; i++){
            offset[i].x = 6 - i;
            offset[i].y = 0;
        }
        init_offset(offset);
        delete [] offset;
        colour_ = COLOR_I;
        orientation_ = HORIZONTAL;
}

Shape_L::Shape_L(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        for(uint8 i = 0; i < (size - 1); i++){
            offset[i].x = 3 + i;
            offset[i].y = 0;
        }
        offset[size - 1].x = 5;
        offset[size - 1].y = 1;
        init_offset(offset);
        delete [] offset;
        colour_ = 1;
        orientation_ = HORIZONTAL;
}

Shape_J::Shape_J(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        for(uint8 i = 0; i < (size - 1); i++){
            offset[i].x = 5 - i;
            offset[i].y = 0;
        }
        offset[size - 1].x = 3;
        offset[size - 1].y = 1;
        init_offset(offset);
        delete [] offset;
        colour_ = 1;
        orientation_ = HORIZONTAL;
}

Shape_T::Shape_T(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        for(uint8 i = 0; i < (size - 1); i++){
            offset[i].x = 5 - i;
            offset[i].y = 0;
        }
        offset[size - 1].x = 4;
        offset[size - 1].y = 1;
        init_offset(offset);
        delete [] offset;
        colour_ = 1;
        orientation_ = HORIZONTAL;
}

Shape_Z::Shape_Z(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        offset[0].x = 5;
        offset[0].y = 0;
        offset[1].x = 4;
        offset[1].y = 0;
        offset[2].x = 4;
        offset[2].y = 1;
        offset[3].x = 3;
        offset[3].y = 1;
        init_offset(offset);
        delete [] offset;
        colour_ = 1;
        orientation_ = HORIZONTAL;
}

Shape_S::Shape_S(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        offset[0].x = 3;
        offset[0].y = 0;
        offset[1].x = 4;
        offset[1].y = 0;
        offset[2].x = 4;
        offset[2].y = 1;
        offset[3].x = 5;
        offset[3].y = 1;
        init_offset(offset);
        delete [] offset;
        colour_ = 1;
        orientation_ = HORIZONTAL;
}

Shape_O::Shape_O(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        offset[0].x = 5;
        offset[0].y = 0;
        offset[1].x = 4;
        offset[1].y = 0;
        offset[2].x = 5;
        offset[2].y = 1;
        offset[3].x = 4;
        offset[3].y = 1;
        init_offset(offset);
        delete [] offset;
        colour_ = 1;
}