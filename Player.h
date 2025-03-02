#ifndef PLAYER_H
#define PLAYER_H

#include <ncurses.h>
#include<ctime>
#include<cstdlib>


class Player {
  private:
    int xLoc, yLoc, xMax, yMax;
    char character;
    WINDOW *curwin;

public:
  Player(WINDOW *win, int y, int x, char c){
        curwin = win;
        xLoc = x;
        yLoc = y;
        character = c;
        getmaxyx(curwin,yMax,xMax);
        keypad(curwin,TRUE);
  }

  void mvup(){
    mvwaddch(curwin,yLoc,xLoc,' ');
    yLoc--;
    if (yLoc < 1)
      yLoc = yMax - 2;
  }
  void mvdown(){
    mvwaddch(curwin,yLoc,xLoc,' ');
    yLoc++;
    if (yLoc > yMax - 2)
      yLoc = 1;
  }
  void mvleft(){
    mvwaddch(curwin,yLoc,xLoc,' ');
    xLoc--;
    if (xLoc < 1)
      xLoc = xMax - 2;
  }
  void mvright(){
    mvwaddch(curwin,yLoc,xLoc,' ');
    xLoc++;
    if (xLoc > xMax - 2)
      xLoc = 1;
  }
  int getmv(){
    int ch = wgetch(curwin);
    if (ch==KEY_UP)
      mvup();
    if (ch==KEY_DOWN)
      mvdown();
    if (ch==KEY_LEFT)
      mvleft();
    if (ch==KEY_RIGHT)
      mvright();
    return ch;
  }
  void display(){
    mvwaddch(curwin,yLoc,xLoc,character);
  }
};



#endif //PLAYER_H
