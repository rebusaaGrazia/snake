//
// Created by Gabriele Preti on 02/03/25.
//

#ifndef BOARD_H
#define BOARD_H

#include "Snake.h"
#include <ncurses.h>

class Board: public Snake {
protected:
  WINDOW *win;

  int coordApple[1][2];
public:
  Board();

  void generateApple();
  void displayApple();
  void displayBoard();
  void displaySnake();
  void move();

};



#endif //BOARD_H
