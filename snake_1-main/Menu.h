//
// Created by Gabriele Preti on 07/03/25.
//

#ifndef MENU_H
#define MENU_H
#include <iostream>
using namespace std;
#include <ncurses.h>
#include <string>
#include "default_functions.h"
#include "Constant.h"
#include "WindowScelta.h"


class Menu : WindowScelta{ //CLASSE DI APPOGGIO PER IL MIO PROGETTO
            //PROGETTO FINALE USA QUELLA DI MIRKO GIÀ IMPOSTATA CORRETTAMENTE
protected:
    string menuOption[2];
    WINDOW *sfondo;
public:
    bool endGame;
    Menu();
    void display();

    void background(int row, int col);

};



#endif //MENU_H
