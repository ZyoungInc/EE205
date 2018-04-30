#include <iostream>
#include <string>
#include <ncurses.h>
#include <utility>
#include "displayPlayerHUD.hpp"
#include "game-utility.hpp"
#include "Unit.hpp"
//#include "Player.hpp"
#include "Weapon.hpp"

void drawPlayerDisplay(int yMax_, int xMax_, std::string name, int classChoice){
  int yMax = yMax_;
  int xMax = xMax_;

  //make box for avatarHUD
  WINDOW * avatarwin = newwin(yMax-1, xMax-(xMax/4), yMax-11, xMax/2);
  box(avatarwin, 0, 0);
  refresh();
  wrefresh(avatarwin);

  //Create player
  //Player newPlayer(parameter);

  /*//Displays AvatarHUD
  if(classChoice == 1)
    mvwprintw(avatarwin, 1, 1, "%s (Warrior)", name.c_str());
  else
    mvwprintw(avatarwin, 1, 1, "%s (Mage)", name.c_str());
  mvwprintw(avatarwin, 2, 1, "HP: %d/%d", newPlayer.get_health(), newPlayer.get_MAXhealth());
  mvwprintw(avatarwin, 3, 1, "MP: %d/%d", newPlayer.get_mana(), newPlayer.get_MAXmana());
  mvwprintw(avatarwin, 4, 1, "ATK: %d", newPlayer.get_wdamage());
  mvwprintw(avatarwin, 5, 1, "DEF: %d", newPlayer.get_wdefense());
  mvwprintw(avatarwin, 6, 1, "WPN: %s", newPlayer.get_type().c_str());
  mvwprintw(avatarwin, 7, 1, "SOULS: %d", newPlayer.get_souls());
  */
  if(classChoice == 1)
    mvwprintw(avatarwin, 1, 1, "%s (Warrior)", name.c_str());
  else
    mvwprintw(avatarwin, 1, 1, "%s (Mage)", name.c_str());
  mvwprintw(avatarwin, 2, 1, "HP: %d/%d", 10, 10);
  mvwprintw(avatarwin, 3, 1, "MP: %d/%d", 100, 100);
  mvwprintw(avatarwin, 4, 1, "ATK: %d", 5);
  mvwprintw(avatarwin, 5, 1, "DEF: %d", 4);
  mvwprintw(avatarwin, 6, 1, "WPN: Normal");
  mvwprintw(avatarwin, 7, 1, "SOULS: %d", 0);

  wrefresh(avatarwin);
  }
