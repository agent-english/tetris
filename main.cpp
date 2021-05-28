#include <ncurses.h>
#include <unistd.h>
#include <iostream>

#include "shapes.hpp"
#include "field.hpp"
#include "coordinates.hpp"
#include "game.hpp"

int main(){
    Game tetris;
    //tetris.init();
    /* int centre_x = getmaxx(stdscr) / 2; 
    int centre_y = getmaxy(stdscr) / 2;
    std::cout << centre_y << " " << centre_x << std::endl;
    sleep(5); */
    tetris.mainloop();
    return 0;
}