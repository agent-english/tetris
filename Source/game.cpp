#include "game.hpp"
#include "ncurses.h"
#include "field.hpp"
#include "shapes.hpp"
#include <unistd.h>
#include <cstdlib>
#include <ctime>

volatile bool gameOver = false;

Game::Game(){
    score_ = 0;
}

int Game::init(){
    initscr();
    nodelay(stdscr, true); //
    keypad(stdscr, true); //inits keypad
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE); //boarders
    //shapes:
    init_pair(2, COLOR_CYAN, COLOR_CYAN); // I
    init_pair(3, COLOR_BLUE, COLOR_BLUE); // L
    init_pair(4, COLOR_YELLOW, COLOR_YELLOW); // J
    init_pair(5, COLOR_WHITE, COLOR_WHITE); // T
    init_pair(6, COLOR_RED, COLOR_RED); // Z
    init_pair(7, COLOR_MAGENTA, COLOR_MAGENTA); // S
    init_pair(8, COLOR_GREEN, COLOR_GREEN); // O
    curs_set(0); //makes cursor invisible 
    return 0;
}

int Game::mainloop(){
    static bool nextShape = 0;
    Field *field = new Field;
    Shape *currentShape = NULL;
    srand(static_cast<unsigned int>(time(0)));
    while(!gameOver){
        if(currentShape == NULL){
            int randomShape = rand() % 7 + 1;
            switch (randomShape){
                case 1:{
                    Shape_I shape1(field);
                    currentShape = &shape1;
                    moveShape(this, field, currentShape);
                    break;
                }

                case 2:{
                    Shape_J shape2(field);
                    currentShape = &shape2;
                    moveShape(this, field, currentShape);
                    break;
                }

                case 3:{ 
                    Shape_L shape3(field);
                    currentShape = &shape3;
                    moveShape(this, field, currentShape);
                    break;
                }

                case 4:{ 
                    Shape_O shape4(field);
                    currentShape = &shape4;
                    moveShape(this, field, currentShape);
                    break;
                }

                case 5: { 
                    Shape_S shape5(field);
                    currentShape = &shape5;
                    moveShape(this, field, currentShape);
                    break;
                }

                case 6: {
                    Shape_T shape6(field);
                    currentShape = &shape6;
                    moveShape(this, field, currentShape);
                    break;
                }

                case 7: { 
                    Shape_Z shape7(field);
                    currentShape = &shape7;
                    moveShape(this, field, currentShape);
                    break;
                }
            };
            setScore(field);
        }  
        currentShape = NULL;
    }
    this->printGameOver();
    endwin();
    return 0;
}

void moveShape(Game *game, Field *field, Shape *currentShape){
    if(currentShape->is_settable() == false){
        gameOver = true;
        return;
    }
    do{
        field->print_field(); 
        currentShape->print();
        game -> printScore();
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
}

void Game::setScore(Field *field){
    int result = field->checkLines();
    switch(result){
        case 1:
            score_ += 100;
            break;
        case 2:
            score_ += 300;
            break;
        case 3:
            score_ += 700;
            break;
        case 4:
            score_ += 1500;
            break;
        default:
            break;
    };
}

void Game::printScore(){
    mvprintw(0,0, "Score : %d", score_);
}

void Game::printGameOver(){
    sleep(2);
    clear();
    mvprintw(CENTRE_Y,CENTRE_X, "GAME OVER");
    refresh();
    sleep(10);
}
