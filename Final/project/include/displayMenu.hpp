#ifndef DISPLAY_MENU_HPP
#define DISPLAY_MENU_HPP

#include <ncurses.h>

/*Function description : Draw game menu and returns user's choice
/ Input: window max x and y for Ncurses
  Output: user's choice (1 for new game , 2 for quit game) */
int drawMenuDisplay(int yMax_, int xMax_);

#endif // DISPLAY MENU_HPP