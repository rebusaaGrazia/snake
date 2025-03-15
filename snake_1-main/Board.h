#ifndef BOARD_H
#define BOARD_H

#include "Snake.h"
#include <ncurses.h>

class Board: public Snake {
protected:
  WINDOW *win;

  int coordApple[1][2];

public:
  bool gameOver;
  bool gamePaused;
  Board();

  void generateApple();
  void displayApple();
  void displayBoard(int& punteggio);
  int displaySnake(int vel);
  void move();

};



#endif //BOARD_H
