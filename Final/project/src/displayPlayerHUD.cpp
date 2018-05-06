#include <iostream>
#include <string>
#include <ncurses.h>
#include <utility>
#include "displayPlayerHUD.hpp"
#include "game-utility.hpp"
#include "Unit.hpp"
#include "Player.hpp"
#include "Weapon.hpp"

void drawPlayerDisplay(int yMax_, int xMax_, std::string name, int classChoice, Player& p, Weapon& weap){
  int yMax = yMax_;
  int xMax = xMax_;

  //make box for avatarHUD
  WINDOW * avatarwin = newwin(yMax-1, xMax-(xMax/4), yMax-11, xMax/2);
  box(avatarwin, 0, 0);
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
    mvwprintw(avatarwin, 1, 1, "%s (Mage)", name.c_str());
    mvwprintw(avatarwin, 3, 1, "MP: %d/%d", p.get_mana(), p.get_MAXmana());
  }
  mvwprintw(avatarwin, 2, 1, "HP: %d/%d", p.get_health(), p.get_MAXhealth());
  mvwprintw(avatarwin, 4, 1, "ATK: %d", p.get_attack());
  mvwprintw(avatarwin, 5, 1, "DEF: %d", p.get_defense());
  mvwprintw(avatarwin, 6, 1, "WPN: %s %s", weap.get_rarity().c_str(), weap.get_type().c_str());
  mvwprintw(avatarwin, 7, 1, "SOULS: %d", p.get_souls());

  wrefresh(avatarwin);
  }
