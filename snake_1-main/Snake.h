//
// Created by Gabriele Preti on 02/03/25.
//

#ifndef SNAKE_H
#define SNAKE_H
#include <ncurses.h>
#include <iostream>
#include "default_functions.h"
#include "Position.h"
using namespace std;
#include "Constant.h"

class Snake : public Position {
protected:
    bool matrix[rows][cols]; //matrice booleana
    int xMax; //Larghezza e altezza massima terminale
    int yMax;
    WINDOW* snake_win; //finestra per movimento
    int xoff; //offset per centrare matrice booleana nella finestra
    int yoff;

    int head_row; //riga e colonna della testa
    int head_col;


public:
    Snake();
    void position();
    void display();

    void display_good();

    void offsegment();

    void onsegment();

    void move();
};



#endif //SNAKE_H