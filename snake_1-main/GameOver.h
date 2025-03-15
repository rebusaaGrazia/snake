//
// Created by graziacomp on 3/15/25.
//

#ifndef GAMEOVER_H
#define GAMEOVER_H

#include <iostream>
using namespace std;
#include <ncurses.h>
#include "Constant.h"
#include "WindowScelta.h"

class GameOver : public WindowScelta{
protected:
    string overOption[gameoverOptions];
public:
    bool endGame;
    GameOver();
    void display();
};



#endif //GAMEOVER_H
