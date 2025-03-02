#include <iostream>
#include <ncurses.h>
#include "spaceRun.h"
#include "Player.h"
#include <string>
using namespace std;

#define SPACE ' '
#define xWindow 10
#define yWindow 20

void createWindow(WINDOW *win, string stringa){
  refresh();
  box(win, 0, 0);
  mvwprintw(win,0,0, "%s", stringa.c_str());
  //wrefresh(win);
}

void init(WINDOW *win){
  if (!has_colors()) {
    printw("Your terminal does not support colors");
    getch();
  }
  start_color();

  cbreak();    // con ctrl C esce da tutto
  noecho();
  keypad(win, true);
  srand(time(NULL));
}

void displayPause(WINDOW *win){      // inutile --> da fare una bella scritta???
  for (int i =0; i<=LINES/8; i++){
    mvwprintw(win,i+LINES/6,COLS/8,"P");
  }
  for (int i =0; i<=LINES/8; i++){
    mvwprintw(win,LINES/6,i+COLS/8,"P");
  }
  for (int i =0; i<=LINES/8/3; i++){
    mvwprintw(win,i+LINES/6,i+LINES/8+COLS/8,"P");
  }
}

void goPause(WINDOW *win){
  char msg[]="Pause";
  createWindow(win, msg);
  //displayPause(win);
  wrefresh(win);
}
/*
void goMenu(WINDOW *win){
  char msg[]="Menu";
  createWindow(win, msg);
  wrefresh(win);
}*/

void generateApple(WINDOW *win, int num, int from, int to){
  int x, y;
  init_pair(1, COLOR_RED, COLOR_BLACK);
  for (int i =0; i<=num; i++){
    x= rand()%(to-from+1);
    y= rand()%(to-from+1);
    // display on the window
    attron(COLOR_PAIR(1));
    mvwprintw(win, y, x, "$");
    attroff(COLOR_PAIR(1));
  }

}

void goPlay(WINDOW *win, Player *p){    // fatto il moviento di un carattere
  p->display();
  while (p->getmv()!='x'){
    p->display();
    generateApple(win,p->getmv(), xWindow, yWindow);    // TODO: DA SISTEMARE !!!
    wrefresh(win);
  }
}

int main() {
  initscr();
  char msg[]= "snake game 2.0";

  WINDOW *win = newwin(LINES/2, COLS/2, LINES/4, COLS/4);    // box centrata al centro
  //WINDOW *pauseWin= newwin(LINES/4, COLS/4, 3*LINES/8, 3*COLS/8);
  createWindow(win, msg);
  wrefresh(win);
  init(win);

  Player *p=new Player(win, 1,1, '@');    // crea il giocatore nell'arena

  goPlay(win, p);

  /*
  int yB, xB;
  getbegyx(win, yB, xB);  // salva x e y di inizio

  // inizio ciclo
  bool gameOver = false, pause = false;

  string choicePause[3]={"Resume", "Restart", "Menù"};
  // Resume: continua la partita
  // Restart lascia la partita e ricomincia
  // Menù: lascia partita e va al menù

  int c, h=0;
  c=getch();
  if (c=='g'){
    while ((c = getch()) != 'x') {
      // mvprintw(0,0,"%d %d", yB, xB);
      // mvwprintw(win,0,0,"%c", c);
  /*
      for (int i=0; i<3; i++){
        if (i==h)
          wattron(win, A_REVERSE);
        mvwprintw(win, i+1, 1, "%s", choicePause[i].c_str());
        wattron(win, A_REVERSE);
      }* /

      if (c==' '){
        if (!pause){
          clear();
          win=newwin(LINES/4, COLS/4, 3*LINES/8, 3*COLS/8);
          goPause(win);
          pause = true;
        }
      }
    }
  }*/
  getch();
  endwin();

  return 0;
}