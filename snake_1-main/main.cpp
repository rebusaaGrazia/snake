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

int main(int argc, char *argv[]) {
    initscr();
    refresh();
    noecho();
    keypad(stdscr, true);
    int punteggio=0;

    bool END=false;
    while (!END) {
        wrefresh(stdscr);
      	//menu principale del gioco
      	Menu menu = Menu();          // << soluzione del non refresh da mirko
    	menu.display();
    	if (!menu.endGame) {
        	Board board = Board();

        	// devo mandargli velocita di gioco e altro ?
        	punteggio=board.displaySnake(5);
        	if (board.gameOver){
          		// gameOver
                wrefresh(stdscr);  // inutile?
                GameOver gameOver = GameOver();
                gameOver.display();
                END=gameOver.endGame;

                // salvataggio dati del livello finito
                // azzerare tutti i dati del giocatore

    		}else if (board.gamePaused){
                  // game paused
                  wrefresh(stdscr);  // inutile?
                  PauseExit pause = PauseExit();
                  pause.display();
                  END=pause.endGame;
                  // nessun azzeramento dei dati
            }
            printw("ultimo punteggio: %d", punteggio);
     	} else if (menu.endGame) {
        	attron(A_BOLD);
        	printw("Terminazione Programma - Premere qualsiasi Tasto");
        	attroff(A_BOLD);
            END=menu.endGame;
    	}
    }



    wrefresh(stdscr);



    getch();
    //delwin(board);
    endwin();
    return 0;
}
