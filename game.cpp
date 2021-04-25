#include "game.hpp"
#include "ncurses.h"
#include "field.hpp"
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
    Field *field = new Field;
    //while(!gameOver){
        field->print_field();
        refresh();
    //}
    sleep(100);
    return 0;
}
