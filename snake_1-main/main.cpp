#include <iostream>

#include "PauseExit.h"
using namespace std;
#include <ncurses.h>
#include <string>
#include "Snake.h"
#include "Board.h"
#include "Menu.h"
#include "default_functions.h"

int main(int argc, char *argv[]) {
    initscr();
    refresh();
    noecho();
    keypad(stdscr, true);

    Menu start = Menu();
    int i = start.Navigate(); //menu che implementa il lancio del gioco
    if (i == 0) {
        //printw("Welcome to Snake!");
        //Snake snake = Snake();
        //snake.display();
        //snake.move();
        Board board = Board();
        board.displaySnake();
        //board.move();
    }
    else if (i == 1) {
        attron(A_BOLD);
        printw("Terminazione Programma - Premere qualsiasi Tasto");
        attroff(A_BOLD);
    }






    getch();
    //delwin(board);
    endwin();
    return 0;
}
