#include <iostream>

#include "PauseExit.h"
using namespace std;
#include <ncurses.h>
#include <string>
#include "Snake.h"
#include "Board.h"
#include "menu.h"
#include "Constant.h"
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
    curs_set(0);
    keypad(stdscr, true);
    int punteggio=0, vel=2, liv=1, valMela=2, bonus=10;
    bool ricomincia=false;
    bool END=false, classific=false;
    const char* voices[3] = {"Nuova partita", "Visualizza classifica", "Esci"};
    char titolo[50] = "- MENU (seleziona una voce e premi invio) -";

    while (!END) {
        wrefresh(stdscr);

      	//menu principale del gioco
        if (!ricomincia){
            background(rows, cols);

            //menu
            Menu menu_generale = Menu(voices, 3);
            menu_generale.display(titolo);

            classific=menu_generale.classificaOpen;
            END=menu_generale.endGame;
            //liv=menu_generale.get_bonus(menu_generale.livello_scelto);
            //vel=menu_generale.get_velocita(menu_generale.livello_scelto);
            //valMela=menu_generale.get_valoreMela(menu_generale.livello_scelto);

		}
    	if (!END || classific) {
            // area di gioco
            clear();
        	Board board = Board();	// da sistemare con le opzioni del menu di mirko

        	// devo mandargli velocita di gioco
        	punteggio=board.displaySnake(vel, liv, valMela);

            if (punteggio!=0) {
              punteggio=punteggio*bonus;
              update_file(punteggio);
            }

        	if (board.gameOver){
          		// gameOver
                clear();
                GameOver gameOver = GameOver();
                gameOver.display(punteggio);
                END=gameOver.endGame;
                ricomincia=gameOver.ricomincia;

    		}else if (board.exitFromGame) END=true;
     	}
        wclear(stdscr);
    }
    wrefresh(stdscr);

    getch();
    endwin();
    return 0;
}
