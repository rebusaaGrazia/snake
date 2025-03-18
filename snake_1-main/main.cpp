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
    bool ricomincia=false;
    bool END=false;

    while (!END) {
        wrefresh(stdscr);

      	//menu principale del gioco
        if (!ricomincia){
      		Menu menu = Menu();          // << soluzione del non refresh da mirko
    		menu.display();
            END=menu.endGame;
		}
    	if (!END) {
        	Board board = Board();	// da sistemare con le opzioni del menu di mirko

        	// devo mandargli velocita di gioco
        	punteggio=board.displaySnake(2);
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
