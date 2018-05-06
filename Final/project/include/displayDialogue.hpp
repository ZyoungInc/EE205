#include <ncurses.h>
#include <string>
#include "Weapon.hpp"

void displayOpeningDiag(int yMax_, int xMax_);

void displayEndingDiag(int yMax_, int xMax_);

bool displayStageDiag(int yMax_, int xMax_, int stage);

void displayDeathDiag(int yMax_, int xMax_);

bool displayWeaponDrop(int yMax_, int xMax_, Weapon w);
