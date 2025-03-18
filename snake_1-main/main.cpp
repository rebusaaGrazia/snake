#include <iostream>

#include "PauseExit.h"
using namespace std;
#include <ncurses.h>
#include <string>
#include "Snake.h"
#include "Board.h"
#include "Menu.h"
#include "GameOver.h"
#include "default_functions.h"

// stampa della finestra di sfondo
void background(int row, int col) {
  WINDOW *sfondo = newwin(rows+8, cols+8, (LINES/2)-(rows/2)-4, (COLS/2)-(cols/2)-4);
  box(sfondo, 0, 0);
  refresh();
  char ch=' ';
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  wattron(sfondo,A_REVERSE);
  wattron(sfondo,A_BOLD);
  wattron(sfondo,COLOR_PAIR(1));
  // stampa righe sopra e sotto
  for (int i = 0; i < cols+6; i++) {
    for (int j = 0; j < rows+6; j++) {
      mvwprintw(sfondo, j+1, i+1, "%c", ch);
    }
  }
  //wattroff(sfondo,COLOR_PAIR(1));


  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  wattron(sfondo,COLOR_PAIR(1));
  mvwprintw(sfondo, rows/4, cols/2, "Menu");
  wattroff(sfondo,COLOR_PAIR(1));

  //wattroff(sfondo,A_BOLD);
  //wattroff(sfondo,A_REVERSE);

  wrefresh(sfondo);
}

int main(int argc, char *argv[]) {
    initscr();
    refresh();
    noecho();
    keypad(stdscr, true);
    int punteggio=0;
    bool ricomincia=false;
    bool END=false;

    while (!END) {
        wrefresh(stdscr);

      	//menu principale del gioco
        if (!ricomincia){
            background(rows, cols);
      		Menu menu = Menu();          // << soluzione del non refresh da mirko
    		menu.display();
            END=menu.endGame;
		}
    	if (!END) {
        	Board board = Board();	// da sistemare con le opzioni del menu di mirko

        	// devo mandargli velocita di gioco
        	punteggio=board.displaySnake(2, 50);
        	if (board.gameOver){
          		// gameOver
                clear();
                GameOver gameOver = GameOver();
                gameOver.display(punteggio);
                //wrefresh(stdscr);
                END=gameOver.endGame;
                ricomincia=gameOver.ricomincia;

                // salvataggio dati del livello finito
                // azzerare tutti i dati del giocatore

    		}else if (board.exitFromGame) END=true;
            //printw("ultimo punteggio: %d", punteggio);
     	}
        //wrefresh(stdscr);
        wclear(stdscr);
    }



    wrefresh(stdscr);



    getch();
    //delwin(board);
    endwin();
    return 0;
}
