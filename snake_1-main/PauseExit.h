//
// Created by Gabriele Preti on 10/03/25.
//

#ifndef PAUSEEXIT_H
#define PAUSEEXIT_H
#include <iostream>
using namespace std;
#include <ncurses.h>
#include <string>
#include "default_functions.h"
#include "Constant.h"


class PauseExit {
protected:
    std::string options[menu_options];
    int pointing;
    WINDOW *menu_win_pause;
public:
    PauseExit();
    int Navigate();

};



#endif //PAUSEEXIT_H
