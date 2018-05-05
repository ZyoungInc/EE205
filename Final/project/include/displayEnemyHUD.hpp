#ifndef DISPLAYENEMYHUD_HPP
#define DISPLAYENEMYHUD_HPP
#include <iostream>
#include <string>
#include <ncurses.h>
#include "Enemy.hpp"

void drawEnemyDisplay(int yMax_, int xMax_, Enemy& newEnemy);

#endif //DISPLAYENEMYHUD_HPP
