//
// Created by Gabriele Preti on 02/03/25.
//

#include <iostream>
using namespace std;
#include <cmath>
#include "Board.h"
#include "Constant.h"

Board::Board(): Snake::Snake(){
  Board::coordApple[0][0] = 0;
  Board::coordApple[0][1] = 0;

}

void Board::randPositionApple(){
    Board::coordApple[0][0] = rand()%rows;
    Board::coordApple[0][1] = rand()%cols;
}

void Board::displayBoard(){
    box(snake_win, 0, 0);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == true) {
                wattron(snake_win, A_REVERSE);
            }
            mvwprintw(snake_win, i+ (xoff)/2, j + (yoff)/2, "%d", matrix[i][j]);
            wattroff(snake_win, A_REVERSE);
        }
    }
    wrefresh(snake_win);
}

void Board::displaySnake(){
    curs_set(0);
    //timeout(10);
    halfdelay(5);        // ciò che dipende dal livello
    //nodelay(snake_win, true);
    //int direction = 2;
    bool end = false;
    while (!end) {
      int val= wgetch(Board::snake_win);
        if (Position::Dups() == true) {        // eredito dups che controlla se snake ha colpito se stesso
            end = true;
            mvprintw(0, 0, "%s", "MORTO! - SERPENTE SI E' MORSO");
            refresh();
        }
        else if (val == 16) {    // ctrl P
            end = true;
            mvprintw(0, 0, "%s", "PAUSA");
            refresh();
        }
        else {
            if (val != ERR) {
              Snake::move(val);
              }
        }
        //napms(200);
        Board::displayBoard();
}

  }