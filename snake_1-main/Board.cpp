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