/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "display.hpp"

Display::drawGame() {
  //clear whole screen
  clear();

  //make box for dialogue
  WINDOW * dialoguewin = newwin(yMax-12, xMax-1, 1, 1);
  box(dialoguewin, 0, 0);
  refresh();
  wrefresh(dialoguewin);

  //make box for avatarHUD
  WINDOW * avatarwin = newwin(yMax-1, xMax-(xMax/4), yMax-11, xMax/2);
  box(avatarwin, 0, 0);
  updateAvatarHUD();
  refresh();
  wrefresh(avatarwin);

  //make box for enemyHUD
  WINDOW * enemywin = newwin(yMax-1, xMax-1, yMax-11, xMax-(xMax/4));
  box(enemywin, 0, 0);
  updateEnemyHUD();
  refresh();
  wrefresh(enemywin);

  //make box for options
  WINDOW * optionwin = newwin(yMax-1, xMax/2, yMax-11, 1);
  box(optionwin, 0, 0);
  updateOptions();
  refresh();
  wrefresh(optionwin);
}
//updates dialogue in dialogue window
int Display::updateDialogue(std::vector<std::string> Dialogue, int yshift){

  //grab dialogue vector and convert to string

  //update dialogue window
  mvwprintw(dialoguewin, yshift, 1, "%s", Dialogue);
  refresh();
  wrefresh(dialoguewin);
  return yshift+1;
}
int Display::updateCombat(int name, int damage, int yshift){
  mvwprintw(dialoguewin, yshift, 1, "%d was attacked for %d damage", name, damage);
  wrefresh(dialoguewin);
  return yshift+1;
}
int Display::updateDeath(int name, int yshift){
  mvwprintw(dialoguewin, yshift, 1, "The %d died", name);
  wrefresh(dialoguewin);
  return yshift+1;
}

void Display::updateAvatarHUD(std::string name, int health, int mana, int attack, int defense){
  mvwprintw(avatarwin, 1, 1, "%s", name);
  mvwprintw(avatarwin, 2, 1, "%d", health);
  mvwprintw(avatarwin, 3, 1, "%d", mana);
  mvwprintw(avatarwin, 4, 1, "%d", attack);
  mvwprintw(avatarwin, 5, 1, "%d", defense);
  wrefresh(avatarwin);

}

void Display::updateEnemyHUD(std::string name, int health, int mana, int attack, int defense){
  mvwprintw(enemywin, 1, 1, "%s", name);
  mvwprintw(enemywin, 2, 1, "%d", health);
  mvwprintw(enemywin, 3, 1, "%d", mana);
  mvwprintw(enemywin, 4, 1, "%d", attack);
  mvwprintw(enemywin, 5, 1, "%d", defense);
  wrefresh(enemywin);
}

void Display::updateOptions(){
  keypad(optionwin, true);

  string Options[5] = {"Spell 1", "Spell 2", "Spell 3", "Spell 4", "Flee"};
  int choice;
  int highlight = 0;

  while(1)
  {
      for(int i = 0; i < 5; i++)
      {
          if(i == highlight)
              wattron(optionwin, A_REVERSE);
          mvwprintw(optionwin, i+1, 1, startMenu[i].c_str());
          wattroff(optionwin, A_REVERSE);
      }
      choice = wgetch(optionwin);

      switch(choice)
      {
          case KEY_UP:
              highlight--;
              if(highlight == -1)
                  highlight = 0;
              break;
          case KEY_DOWN:
              highlight++;
              if(highlight == 5)
                  highlight = 4;
              break;
          default:
              break;
      }
      if(choice == 10)
          break;
      }
      if(Options[highlight] == Options[0])
        //attack with spell1
      else if(Options[highlight] == Options[1])

      else if(Options[highlight] == Options[2])

      else if(Options[highlight] == Options[3])

      else if(Options[highlight] == Options[4])
    }

      //Getters
      int Display::get_yshift() {return yshift;}

      //Setters
      void Display::set_yshift(int y) {yshift = y;}
