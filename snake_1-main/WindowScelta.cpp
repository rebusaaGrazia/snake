//
// Created by graziacomp on 3/15/25.
//
#include <iostream>
using namespace std;
#include "WindowScelta.h"
#include <ncurses.h>
#include "default_functions.h"

WindowScelta::WindowScelta(int n, string Name) {
  name=Name;
  numChoices = n;
  win = standard_win(10, 20);
  keypad(win, true);
  box(win, 0, 0);
  wrefresh(win);

  pointing = 0;
};

// window che fa il display a seconda del numero delle opzioni
int WindowScelta::windowDisplay(string Op[], int length){
  curs_set(0);
  wclear(win);
  wrefresh(stdscr);
  box(win, 0, 0);
  int end_loop = false;
  while (end_loop != true) {
    mvwprintw(win, 0, 0, "%s", name.c_str());
    for (int i = 0; i < length; i++) {
      if (i == pointing) {
        wattron(win, A_BOLD);
      }
      mvwprintw(win, i + 1, 2, "%s", Op[i].c_str());
      wattroff(win,A_BOLD);
    }
    wrefresh(win);
    int ch = wgetch(win);
    switch (ch) {
      case KEY_UP:
        pointing--;
      if (pointing == -1) {
        pointing = length - 1;
      }
      break;
      case KEY_DOWN:
        pointing++;
      if (pointing >= length) {
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
  wclear(win);
  wrefresh(win);
  return pointing;
};