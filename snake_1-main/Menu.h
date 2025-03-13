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


class Menu { //CLASSE DI APPOGGIO PER IL MIO PROGETTO
            //PROGETTO FINALE USA QUELLA DI MIRKO GIÀ IMPOSTATA CORRETTAMENTE
protected:
    std::string options[2];
    int pointing;
    int ops_firstmenu;
    WINDOW *menu_win;
public:
    Menu();
    int Navigate();

};



#endif //MENU_H
