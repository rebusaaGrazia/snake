#include <iostream>
using namespace std;
#include <cmath>
#include <ncurses.h>
#include "Board.h"
#include "Constant.h"


Board::Board(): Snake::Snake(){  // >>
  Board::coordApple[0][0] = 0;
  Board::coordApple[0][1] = 0;
  generateApple();
  gameOver = false;
  gamePaused = false;
  win = newwin(rows+2, cols+2, xPosCenter, yPosCenter);
  keypad(win, true);
  srand(time(0));
}

// genera casualmente la posizione di $
void Board::generateApple(){        // >>
    srand(time(0));
    Board::coordApple[0][0] = rand()%rows;
    Board::coordApple[0][1] = rand()%cols;
}

// fa il display della $
void Board::displayApple(){        // >>
  mvwprintw(win, coordApple[0][0]+1, coordApple[0][1]+1, "$");
}

// stampa l'area di gioco : serpente e mela
void Board::displayBoard(int& punteggio){        // >>
    box(win, 0, 0);
    char ch;
    bool found=false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == true) {
              ch='o';
              if (head_row==i && head_col==j){
                if (head_row==coordApple[0][0] && head_col==coordApple[0][1]) {
                  // mela trovata
                  Board::generateApple();
                  found=true;
                  ch='R';

                  // incremento punteggio
                  punteggio++;
                } else ch = '@';
              }else{

              }

            }else{
              ch=' ';
            }
			if (!found) Board::displayApple();		// se la mela non è stata mangiata fai il display
            else {									// se no fai il display della mela al turno dopo
              // mela trovata
              wattron(win, A_REVERSE);
              found=false;
            }
            mvwprintw(win, i+1, j+1, "%c", ch);
            wattroff(win, A_REVERSE);
        }
    }
    wrefresh(win);
}

// avvia il gioco con risposta ai movimenti dati dall'utente
int Board::displaySnake(int vel){
    curs_set(0);
    halfdelay(vel);        // ciò che dipende dal livello
    int direction = 2;
    bool end = false;
    int ch, punteggio=0;
    while (!end) {
        ch = wgetch(win);
        if (Position::Dups() == true) {        // dups controlla se snake ha colpito se stesso
            end = true;
            mvprintw(0, 0, "%s", "MORTO! - SERPENTE SI E' MORSO");
            gameOver = true;
            refresh();
        } else if (ch == 16) {    // ctrl P
            end = true;
            mvprintw(0, 0, "%s", "PAUSA");
            gamePaused = true;
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
        mvwprintw(win, 0, 0, "%d", coordApple[0][0]);
        displayBoard(punteggio);
        napms(200);
    }
    return punteggio;
}