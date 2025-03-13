//
// Created by Gabriele Preti on 02/03/25.
//

#include <iostream>
using namespace std;
#include <cmath>
#include <ncurses.h>
#include "Board.h"
#include "Constant.h"


Board::Board(): Snake::Snake(){
  Board::coordApple[0][0] = 0;
  Board::coordApple[0][1] = 0;
  generateApple();
  win = newwin(rows+2, cols+2,LINES/4, COLS/4);
  keypad(win, true);
  box(win, 0, 0);
  srand(time(0));
}

void Board::generateApple(){        // >>
    srand(time(0));
    Board::coordApple[0][0] = rand()%rows;
    Board::coordApple[0][1] = rand()%cols;
}

void Board::displayApple(){        // >>
  mvwprintw(win, coordApple[0][0]+1, coordApple[0][1]+1, "$");
}

void Board::displayBoard(){        // >>
    box(win, 0, 0);
    char ch;
    bool found=false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == true) {
              ch='o';
              if (head_row==i && head_col==j) ch = '@';
              if (j==coordApple[0][0] && i==coordApple[0][1]){        //<<
                found=true;

              }else{Board::displayApple();}
                //wattron(win, A_REVERSE);
            }else{
              ch=' ';
              }

            mvwprintw(win, i+1, j+1, "%c", ch);
            //wattroff(win, A_REVERSE);
        }
    }
    wrefresh(snake_win);
}

void Board::displaySnake(){
    curs_set(0);
    halfdelay(5);        // ciò che dipende dal livello
    int direction = 2;
    bool end = false;
    while (end != true) {
        int ch = wgetch(win);            // ciò che prende move
        if (Position::Dups() == true) {        // eredito dups che controlla se snake ha colpito se stesso
            end = true;
            mvprintw(0, 0, "%s", "MORTO! - SERPENTE SI E' MORSO");
            refresh();
        } else if (ch == 16) {    // ctrl P
            end = true;
            mvprintw(0, 0, "%s", "PAUSA");
            refresh();
        }
        else {
            if (ch != ERR) {
                switch (ch) {
                    case KEY_UP:
                        if (direction != -1){ direction = 1;}
                        end = Position::Dups();
                    break;
                    case KEY_DOWN:
                        if (direction != 1){ direction = -1;}
                        end = Position::Dups();
                    break;
                    case KEY_LEFT:
                        if (direction != 3){ direction = 2;}
                        end = Position::Dups();
                    break;
                    case KEY_RIGHT:
                        if (direction != 2){ direction = 3;}
                        end = Position::Dups();
                    break;
                    default:
                        break;
                }
            }
            if (direction == 1){
                Snake::moveup();

            }
            else if (direction == -1){
                Snake::movedown();
            }
            else if (direction == 2){
                Snake::moveleft();
            }
            else if (direction == 3){
                Snake::moveright();
            }
        }
        Board::displayBoard();
        napms(200);
    }
}