#include "game.hpp"
#include "ncurses.h"
#include "field.hpp"
#include "shapes.hpp"
#include <unistd.h>

volatile int gameOver = 0;

int Game::init(){
    initscr();
    nodelay(stdscr, true); // 
    keypad(stdscr, true); //inits keypad
    start_color();
    curs_set(0); //makes cursor invisible 
    return 0;
}

int Game::mainloop(){
    static bool gameOver = 0;
    static bool nextShape = 0;
    Field *field = new Field;
    Shape *currentShape = NULL;
    while(!gameOver){
        if(currentShape == NULL){
            //здесь я думал написать функцию, которая создает объект и возвращает на него указатель.
            //но из-за некоторых проблем я решил отложить подобную реализацию на потом
            int randomShape = srand(time(0)) % 7 + 1;
            Shape *shape = NULL;
            switch (randomShape){
                case 1:
                    Shape_I shape;
                    break;

                case 2:
                    Shape_J shape;
                    break;
 
                case 3: 
                    Shape_L shape;
                    break;

                case 4: 
                    Shape_O shape;
                    break;
                
                case 5: 
                    Shape_S shape;
                    break;
                
                case 6: 
                    Shape_T shape;
                    break;
                
                case 7: 
                    Shape_Z shape;
                    break;
            }
            currentShape = &shape;   
        }
        currentShape->move();
        field->print_field();
        refresh();
        if(currentShape->set_shape(field)){
            field->delete_lines();
            currentShape->~Shape();
            currentShape = NULL;
        }
    }
    //sleep(100);
    return 0;
}
