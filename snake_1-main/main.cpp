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

                // salvataggio dati del livello finito
                // azzerare tutti i dati del giocatore

    		}else if (board.gamePaused){
                  // game paused
                  //wclear(stdscr);
                  //PauseExit pause = PauseExit();
                  //pause.display();
                  //END=pause.endGame;
                  // nessun azzeramento dei dati
            }
            //printw("ultimo punteggio: %d", punteggio);
     	} else if (menu.endGame) {
            END=menu.endGame;
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
