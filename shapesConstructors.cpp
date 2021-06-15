#include "shapes.hpp"

Shape_I::Shape_I(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        for(uint8 i = 0; i < size; i++){
            offset[i].x = 6 - i;
            offset[i].y = 0;
        }
        init_offset(offset);
        delete [] offset;
        colour_ = 1;
}

Shape_J::Shape_J(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        for(uint8 i = 0; i < (size - 1); i++){
            offset[i].x = 4;
            offset[i].y = i;
        }
        offset[size - 1].x = 5;
        offset[size - 1].y = 2;
        init_offset(offset);
        delete [] offset;
        colour_ = 1;
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

Shape_L::Shape_L(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        for(uint8 i = 0; i < (size - 1); i++){
            offset[i].x = 5;
            offset[i].y = i;
        }
        offset[size - 1].x = 4;
        offset[size - 1].y = 2;
        init_offset(offset);
        delete [] offset;
        colour_ = 1;
}

Shape_Z::Shape_Z(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        offset[0].x = 4;
        offset[0].y = 0;
        offset[1].x = 5;
        offset[1].y = 1;
        offset[2].x = 4;
        offset[2].y = 1;
        offset[3].x = 5;
        offset[3].y = 2;
        init_offset(offset);
        delete [] offset;
        colour_ = 1;
}

Shape_T::Shape_T(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        for(uint8 i = 0; i < (size - 1); i++){
            offset[i].x = 5;
            offset[i].y = i;
        }
        offset[size - 1].x = 4;
        offset[size - 1].y = 1;
        init_offset(offset);
        delete [] offset;
        colour_ = 1;
}

Shape_S::Shape_S(Field *field) : Shape(field, 4){ //вызывается конструктор Shape
        uint8 size = get_size();
        Position *offset = new Position[size];
        offset[0].x = 5;
        offset[0].y = 0;
        offset[1].x = 5;
        offset[1].y = 1;
        offset[2].x = 4;
        offset[2].y = 1;
        offset[3].x = 4;
        offset[3].y = 2;
        init_offset(offset);
        delete [] offset;
        colour_ = 1;
}