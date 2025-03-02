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

  WINDOW *win = newwin(LINES/2, COLS/2, 20, 10);    // grandezza y, x , posizione primo char y,x
  refresh();

  // (int) (char c = 'g')
  box(win, 0, 0);   // you can type the asci number for a letter that will create the box
  mvwprintw(win, 10, 1, "This is my box");
  wrefresh(win);

  int x=10, y=10;
  move(y,x);

  init_pair(1, COLOR_RED, COLOR_BLACK);
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


  // halfdelay(); for the TIME; OR timeout();
  // TODO: il movimento del serpente: deve andare dritto anche se non si preme niente

  mvprintw(0,0,"%d", c);

  getch();

  endwin();

  return 0;
}