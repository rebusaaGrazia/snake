#include <iostream>
using namespace std;
#include <cmath>
#include <ncurses.h>
#include "Board.h"
#include "Constant.h"
#include "PauseExit.h"

Board::Board(): Snake::Snake(){  // >>
  Board::coordApple[0][0] = 0;
  Board::coordApple[0][1] = 0;
  generateApple();
  gameOver = false;
  gamePaused = false;
  win = newwin(rows+2, cols+2, xPosCenter, yPosCenter);
  keypad(win, true);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  start_color();
  srand(time(0));
}

// genera casualmente la posizione di $
// modifica alla funzione generateApple
void Board::generateApple() {
    bool validPosition = false;

    while (!validPosition) {
        Board::coordApple[0][0] = rand() % rows;
        Board::coordApple[0][1] = rand() % cols;

        // Verifica se la mela non si sovrappone al corpo del serpente
        validPosition = !(matrix[coordApple[0][0]][coordApple[0][1]] == 1);
    }
}


// fa il display della $
void Board::displayApple(){        // >>
  start_color();
  init_pair(1, COLOR_RED, COLOR_BLACK);
  wattron(win,COLOR_PAIR(1));
  mvwprintw(win, coordApple[0][0]+1, coordApple[0][1]+1, "$");
  wattroff(win,COLOR_PAIR(1));

}

// stampa l'area di gioco : serpente e mela
void Board::displayBoard(int& punteggio){        // >>
    box(win, 0, 0);
    char ch;
    bool found=false;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
          	wattron(win,A_REVERSE);
            if (matrix[i][j] == true) {
              ch='o';
              if (head_row==i && head_col==j){
                ch = '@';
              }
              if (head_row==coordApple[0][0] && head_col==coordApple[0][1]) {
                  // mela trovata
                  Board::generateApple();
                  found=true;

                  // incremento punteggio
                  punteggio++;
              }
            }else{
              wattroff(win, A_REVERSE);
              ch=' ';
            }
			if (!found) {
              // mela trovata
              wattroff(win, A_REVERSE);			// evidenzio il serpente
              found=false;
            }
            init_pair(2, COLOR_BLUE, COLOR_BLACK);
            wattron(win, A_BOLD);
            wattron(win,COLOR_PAIR(2));
            mvwprintw(win, i+1, j+1, "%c", ch);
            wattroff(win, COLOR_PAIR(2));
            wattroff(win, A_REVERSE);
            wattron(win, A_BOLD);
        }
    }
    if (!found) Board::displayApple(); // se la mela non è stata mangiata (se no sovrapporrebbe al serpente)
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
            //mvprintw(0, 0, "%s", "MORTO! - SERPENTE SI E' MORSO");
            gameOver = true;
            refresh();
        } else if (ch == 16) {    // ctrl P
            //mvprintw(0, 0, "%s", "PAUSA");
            gamePaused = true;

            PauseExit pause = PauseExit();
            pause.display(punteggio);
            end = pause.endGame;
            if (pause.aggPunteggio) punteggio=0;	// azzeramento del punteggio

            refresh();
        } else {
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