#include <ncurses.h>
using namespace std;


int main() {

  initscr();
  if (!has_colors()) {
    printw("Your terminal does not support colors");
    getch();
    return -1;
  }
  start_color();


  // cbreak(); --> ctrl C esce
  // row();    --> ctrl C lo scrive e aspetta per un altro type
  // noecho(); --> non stampa nessun ctrl sullo schermo

  int rows= 30;
  int cols= 120;
  int xPosCenter= (LINES/2) - (rows/2) -1;
  int yPosCenter= (COLS/2) - (cols/2) -1;
  WINDOW *win = newwin(rows+2, cols+2, xPosCenter, yPosCenter);
  refresh();
  box(win, 0, 0);

  WINDOW *sfondo = newwin(rows+8+1, cols+8, xPosCenter-3, yPosCenter-3);    // grandezza y, x , posizione primo char y,x
  wrefresh(sfondo);


  // (int) (char c = 'g')
  box(sfondo, 0, 0);   // you can type the asci number for a letter that will create the box
  curs_set(0);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
  char ch=' ';
  //wattron(sfondo,A_REVERSE);
  // 	wattron(sfondo,A_BOLD);
  wattron(sfondo,COLOR_PAIR(2));
  for (int i = 0; i < cols+6; i++) {
    for (int j = 0; j < rows+6; j++) {
      mvwprintw(sfondo, j+1, i+1, "%c", ch);
    }
  }
  wattroff(sfondo,COLOR_PAIR(2));
  wattroff(sfondo,A_BOLD);
  wattroff(sfondo,A_REVERSE);


/*
  int punteggio=10;
  init_pair(1, COLOR_BLUE, COLOR_BLACK);
  init_pair(3, COLOR_WHITE, COLOR_BLACK);
  wattron(sfondo,COLOR_PAIR(1));
  wattron(sfondo,A_BOLD);
  mvwprintw(sfondo, rows+7, 3, "Livello: ");
  mvwprintw(sfondo, rows+7, cols/2-2, "Score: ");
  mvwprintw(sfondo, rows+7, cols-11, "Speed: ");
  wattroff(sfondo,COLOR_PAIR(1));


  wattron(sfondo,COLOR_PAIR(3));
  mvwprintw(sfondo, rows+7, 3+10, "%d", punteggio);
  mvwprintw(sfondo, rows+7, cols/2+10-4, "%d", punteggio);
  mvwprintw(sfondo, rows+7, cols-3, "%d", punteggio);
  wattroff(sfondo,COLOR_PAIR(3));
  wattroff(sfondo,A_BOLD);*/


  //mvwprintw(sfondo, 10, 1, "This is my box");
  wrefresh(sfondo);
  wrefresh(win);

/*  int x=10, y=10;
  move(y,x);

  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  attron(COLOR_PAIR(1));
  printw("Hello World \t --> $");
  attroff(COLOR_PAIR(1));

  keypad(win, TRUE);

  int c= wgetch(win);
  if (c == KEY_UP) {            // per usare le frecce
    mvwprintw(win, 11, 1, "upp");
    wrefresh(win);
  }
  // 119 == w
  // 97  == a
  // 115 == s
  // 100 == d

  //clear();  // clear the entire window
  //move(0,0);

  mvprintw(0,0,"%d", c);*/

  getch();

  endwin();

  return 0;
}