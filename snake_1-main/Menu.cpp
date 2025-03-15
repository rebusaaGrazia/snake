#include "Menu.h"

Menu::Menu(): WindowScelta(menuOptions, "Menu") {
    endGame=false;

    menuOption[0] = "Inizio Partita";
    menuOption[1] = "Esci";
}

void Menu::display() {
    int i=WindowScelta::windowDisplay(menuOption, menuOptions);
    if (i==1) endGame=true;
    else endGame=false;
}
