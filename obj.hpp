#include <ncurses.h>
#define FIELD_SIZE_X 20
#define FIELD_SIZE_Y 10

struct Position{
    int x,y;
}


template <class T>
class Shape{
public:
    explicit Shape(const int size) : size_(size){}

    virtual void print();
    void changePosition(int8 direction);
    virtual ~Shape();
private:
    T *block_;
    int size_;
    Position *position_;
};

class Field : public Shape{
    Field() : Shape<short int*>(FIELD_SIZE_y) {}
    
    void print(){
        for(int i = FIELD_SIZE_Y; i >= 0 ; i--){
            for(int j = FIELD_SIZE_X; j >= 0 ; j--){
                move(getPosition() + i, j);
                printw("%d", (block_[i] >> j) && 1); //в блоке хранится вся строка. для отображения одного символа из 10 пока что буду использовать такой синтаксис
            }
        }
    }

    void deleteLine(int lineNum);
private:
    
};
