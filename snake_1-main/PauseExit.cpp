//
// Created by Gabriele Preti on 10/03/25.
//

#include "PauseExit.h"

PauseExit::PauseExit() {
    menu_win_pause = standard_win(10, 20);
    keypad(menu_win_pause, TRUE);
    pointing = 0;
    box(menu_win_pause, 0, 0);
    wrefresh(menu_win_pause);

    options[0] = "Riprendi";
    options[1] = "Cambia Livello";
    options[2] = "Esci";

    pointing = 0;
}

int PauseExit::Navigate() {
    curs_set(0);
    wclear(menu_win_pause);
    box(menu_win_pause, 0, 0);
    int end_loop = false;
    while (end_loop != true) {
        for (int i = 0; i < menu_options; i++) {
            if (i == pointing) {
                wattron(menu_win_pause, A_BOLD);
            }
            mvwprintw(menu_win_pause, i + 1, 2, options[i].c_str());
            wattroff(menu_win_pause,A_BOLD);
        }
        wrefresh(menu_win_pause);
        int ch = wgetch(menu_win_pause);
        switch (ch) {
            case KEY_UP:
                pointing--;
            if (pointing == -1) {
                pointing = menu_options - 1;
            }
            break;
            case KEY_DOWN:
                pointing++;
            if (pointing >= menu_options) {
                pointing = 0;
            }
            break;
            default:
                break;
        }

        if (ch == 10) { //invio premuto -> uscita ciclo
            end_loop = true;
        }

    }
    wclear(menu_win_pause);
    wrefresh(menu_win_pause);
    return pointing;
}

