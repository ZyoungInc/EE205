#ifndef DISPLAYPLAYERHUD_HPP
#define DISPLAYPLAYERHUD_HPP
#include <iostream>
#include <string>
#include <ncurses.h>
#include "Player.hpp"
#include "Weapon.hpp"

void drawPlayerDisplay(int yMax_, int xMax_, std::string name, int className, Player& p, Weapon& weap);

#endif //DISPLAYPLAYERHUD_HPP
