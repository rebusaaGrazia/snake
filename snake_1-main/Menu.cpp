//
// Created by Gabriele Preti on 07/03/25.
//

#include "Menu.h"
Menu::Menu() {
    menu_win = standard_win(10, 20);
    keypad(menu_win, TRUE);
    pointing = 0;
    box(menu_win, 0, 0);
    wrefresh(menu_win);

    options[0] = "Inizio Partita";
    options[1] = "Esci";

    ops_firstmenu = 2;

    pointing = 0;
}

int Menu::Navigate() {
    curs_set(0);
    wclear(menu_win);
    box(menu_win, 0, 0);
    int end_loop = false;
    while (end_loop != true) {
        for (int i = 0; i < ops_firstmenu; i++) {
            if (i == pointing) {
                wattron(menu_win, A_BOLD);
            }
            //mvwprintw(menu_win, i + 1, 2, options[i].c_str());
            wattroff(menu_win,A_BOLD);
        }
        wrefresh(menu_win);
        int ch = wgetch(menu_win);
        switch (ch) {
            case KEY_UP:
                pointing--;
                if (pointing == -1) {
                    pointing = ops_firstmenu - 1;
                }
                break;
            case KEY_DOWN:
                pointing++;
                if (pointing >= ops_firstmenu) {
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
    wclear(menu_win);
    wrefresh(menu_win);
    return pointing;
}