#include <iostream>
#include <string>
#include <ncurses.h>
#include <utility>
#include "displayPlayerHUD.hpp"
#include "game-utility.hpp"
#include "Unit.hpp"
#include "Player.hpp"
#include "Weapon.hpp"
#include "displayColor.hpp"

void drawPlayerDisplay(int yMax_, int xMax_, std::string name, int classChoice, Player& p){
  int yMax = yMax_;
  int xMax = xMax_;

  //make box for avatarHUD
  WINDOW * avatarwin = newwin(yMax-1, xMax-(xMax/4), yMax-11, xMax/2);
  start_color();
  box(avatarwin, 0, 0);
  BLUEBLACK;
  wbkgd(avatarwin, COLOR_PAIR(4));
  refresh();
  wrefresh(avatarwin);

  //display player stats
  if(classChoice == 1)
  {
    mvwprintw(avatarwin, 1, 1, "%s (Warrior)", name.c_str());
    mvwprintw(avatarwin, 3, 1, "RAGE: %d/%d", p.get_mana(), p.get_MAXmana());
  }
  else
  {
    mvwprintw(avatarwin, 1, 1, "%s (%s Mage)", name.c_str(), p.get_eleType().c_str());
    mvwprintw(avatarwin, 3, 1, "MP: %d/%d", p.get_mana(), p.get_MAXmana());
  }
  mvwprintw(avatarwin, 2, 1, "HP: %d/%d", p.get_health(), p.get_MAXhealth());
  mvwprintw(avatarwin, 4, 1, "ATK: %d", p.get_attack());
  mvwprintw(avatarwin, 5, 1, "DEF: %d", p.get_defense());
  mvwprintw(avatarwin, 6, 1, "WPN: %s %s", p.get_rarity().c_str(), p.get_weapType().c_str());
  mvwprintw(avatarwin, 7, 1, "SOULS: %d", p.get_souls());

  attroff(COLOR_PAIR(4));
  wrefresh(avatarwin);
  }
