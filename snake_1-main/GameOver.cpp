//
// Created by graziacomp on 3/15/25.
//

#include "GameOver.h"

GameOver :: GameOver() : WindowScelta(gameoverOptions, "Game Over") {

  endGame = false;

  overOption[0]="Riprova";
  overOption[1]="Cambia Livello";
  overOption[2]="Esci";
};

void GameOver::display(){
  int i=WindowScelta::windowDisplay(overOption, gameoverOptions);
  if (i==2) endGame = true;
  else endGame = false;
};