#include "PauseExit.h"

PauseExit::PauseExit() : WindowScelta(pauseOptions, "Pausa"){
    endGame = false;

    pauseOption[0] = "Riprendi";
    pauseOption[1] = "Ricomincia";
    pauseOption[2] = "Cambia Livello";
    pauseOption[3] = "Esci";
}

void PauseExit::display() {
    int i=WindowScelta::windowDisplay(pauseOption, pauseOptions);
    if (i==3 || i!=0) endGame=true;        // da sistemare
    else endGame=false;
}

