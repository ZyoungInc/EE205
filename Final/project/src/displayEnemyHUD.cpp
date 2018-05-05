#include <iostream>
#include <string>
#include <ncurses.h>
#include <utility>
#include "displayEnemyHUD.hpp"
#include "game-utility.hpp"
#include "Unit.hpp"
#include "Enemy.hpp"

void drawEnemyDisplay(int yMax_, int xMax_, Enemy& newEnemy){
  int yMax = yMax_;
  int xMax = xMax_;

  //make box for enemyHUD
  WINDOW * enemywin = newwin(yMax-1, xMax-1, yMax-11, xMax-(xMax/4));
  box(enemywin, 0, 0);
  refresh();
  wrefresh(enemywin);
  //Create random enemy
  //randomNum = RandNum(1 , 6);
  //Enemy newEnemy(randomNum);
  //displays enemy HUD
  mvwprintw(enemywin, 1, 1, "%s (Tier %d)", newEnemy.get_name().c_str(), newEnemy.get_tier());
  mvwprintw(enemywin, 2, 1, "HP: %d/%d", newEnemy.get_health(), newEnemy.get_MAXhealth());
  mvwprintw(enemywin, 3, 1, "MP: %d/%d", newEnemy.get_mana(), newEnemy.get_mana());
  mvwprintw(enemywin, 4, 1, "ATK: %d", newEnemy.get_attack());
  mvwprintw(enemywin, 5, 1, "DEF: %d", newEnemy.get_defense());
  mvwprintw(enemywin, 6, 1, "ATR: %s", newEnemy.get_element().c_str());
  mvwprintw(enemywin, 7, 1, "WPN: %s", newEnemy.get_wep_type().c_str());

  wrefresh(enemywin);

}
