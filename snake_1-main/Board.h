//
// Created by Gabriele Preti on 02/03/25.
//

#ifndef BOARD_H
#define BOARD_H

#include "Snake.h"


class Board: public Snake {
protected:

  int coordApple[1][2];
public:
  Board();

  void randPositionApple();
  void displayBoard();

};



#endif //BOARD_H
