#include "game.hpp"
#include "ncurses.h"
#include "field.hpp"
#include "shapes.hpp"
#include <unistd.h>

volatile bool gameOver = false;

int Game::init(){
    initscr();
    nodelay(stdscr, true); //
    keypad(stdscr, true); //inits keypad
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE); //boarders
    init_pair(2, COLOR_CYAN, COLOR_CYAN); // I
    init_pair(3, COLOR_BLUE, COLOR_BLUE);
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(5, COLOR_WHITE, COLOR_WHITE);
    init_pair(6, COLOR_RED, COLOR_RED);
    init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(8, COLOR_GREEN, COLOR_GREEN);
    curs_set(0); //makes cursor invisible 
    return 0;
}

/*int Game::mainloop(){
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
*/

int Game::mainloop(){
    static bool nextShape = 0;
    Field *field = new Field;
    Shape *currentShape = NULL;
    while(!gameOver){
        //do_tick();
        if(currentShape == NULL){
            Shape_I shape(field);
            currentShape = &shape;
            do{
                field->print_field(); 
                currentShape->print(); 
                refresh();
                usleep(50000);
                currentShape->move_shape();
                clear(); 
                if(currentShape->check_hit()){
                    Position *addBlock = new Position[4];
                    for(uint8 i = 0; i < 4; i++){
                        addBlock[i] = currentShape->getPosition(i);
                    }
                    field->fill(addBlock);
                    delete [] addBlock;
                    break;
                }
            } while(true);
            currentShape = NULL;
        }  
    }
    endwin();
    return 0;
}
