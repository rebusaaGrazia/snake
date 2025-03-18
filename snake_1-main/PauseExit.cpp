#include "PauseExit.h"

PauseExit::PauseExit() : WindowScelta(pauseOptions, "Pausa"){
    endGame = false;
    aggPunteggio = false;

    pauseOption[0] = "Riprendi";
    pauseOption[1] = "Ricomincia";
    pauseOption[2] = "Torna al Menu";
    pauseOption[3] = "Esci";
}

void PauseExit::display(int punteggio) {
    int i=WindowScelta::windowDisplay(pauseOption, pauseOptions, punteggio);
    if (i!=0){
      endGame=true;        // non finisce la partita se vuole riprendere
      if (i!=1) aggPunteggio=true;	// bisogna aggiornare la classifica sempre tranne se vuole ricominciare da 0
      else aggPunteggio=false;
    }else endGame=false;


}

