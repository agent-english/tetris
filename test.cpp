#include <ncurses.h>
#include <unistd.h>
#include <iostream>

#define FIELD_SIZE_X 20
#define FIELD_SIZE_Y 10

const int field[FIELD_SIZE_X][FIELD_SIZE_Y] = {0};

void printField(){
    static int x = getmaxx(stdscr) / 2, y = getmaxy(stdscr)/2;
    for(int i = 0; i < FIELD_SIZE_Y; i++){
        move(y++,x);
        addch('1');
        whline(stdscr, ACS_BLOCK, 1);
    }
    for(int i = 0; i < FIELD_SIZE_X; i++){
        
        move(y,++x);
        
        whline(stdscr, ACS_BLOCK, 1);
    }
    
    for(int i = 0; i < FIELD_SIZE_Y; i++){
        move(--y,x);
        whline(stdscr, ACS_BLOCK, 1);
    }
}

int main(){
    initscr();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    curs_set(0);
    int x,y = 0;
    //addstr('ACS_BLOCK');
    //whline(stdscr, ACS_CKBOARD, 2);
    //move(5,5);
    start_color();
    init_pair(1, COLOR_GREEN, COLOR_GREEN); /* create foreground / background combination */
    //attron(COLOR_PAIR(1)); /* use the above combination */
    //attroff(COLOR_PAIR(1)); /* turn color off */
    printField();
    refresh();
    //sleep(100);
    while(1){
        usleep(10000);
        int tmp = getch();
        switch (tmp)
        {
        case KEY_UP:
            y -= 1;
            break;
        case KEY_DOWN:
            y += 1;
            break;
        case KEY_LEFT:
            x -= 2;
            break;
        case KEY_RIGHT:
            x += 2;
            break;
        case 'q':
            endwin();
            return 0;
            break;
        }
        clear();
        move(y,x);
        int a = 1;
        printw("%d", a);
        //printw("CC");
        //printField();
        refresh();
    }
    endwin();
    return 0;
}

