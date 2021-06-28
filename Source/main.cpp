#include <ncurses.h>
#include <unistd.h>
#include <iostream>

#include "shapes.hpp"
#include "field.hpp"
#include "coordinates.hpp"
#include "game.hpp"

int main(){
    Game tetris;
    tetris.init();
    tetris.mainloop();
    return 0;
}
