#include "Menu.h"

Menu::Menu(): WindowScelta(menuOptions, "Menu") {
    //sfondo = newwin(rows+8, cols+8, (LINES/2)-(rows/2)-4, (COLS/2)-(cols/2)-4);
    endGame=false;

    menuOption[0] = "Inizio Partita";
    menuOption[1] = "Esci";
}

void Menu::display() {
    //Menu::background(y+10, x+10);
    int i=WindowScelta::windowDisplay(menuOption, menuOptions, 0);
    if (i==1) endGame=true;
    else endGame=false;
}

void Menu::background(int row, int col) {

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