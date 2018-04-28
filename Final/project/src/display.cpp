/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "display.hpp"
#include "Unit.hpp"
#include <string>

//Constructor
Display::Display(int yshift_, int selecter_) :
	yshift(yshift_),
	selecter(selecter_)	{}

void Display::drawGame() {
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
void Display::updateDialogue(std::vector<std::string> Dialogue){

  //grab dialogue vector and convert to string

  //update dialogue window
  mvwprintw(dialoguewin, this->yshift, 1, "%s", Dialogue);
  refresh();
  wrefresh(dialoguewin);
  set_yshift(yshift+1);
}
void Display::updateCombat(int name, int damage){
  mvwprintw(dialoguewin, this->yshift, 1, "%d was attacked for %d damage", name, damage);
  wrefresh(dialoguewin);
  set_yshift(yshift+1);
}
void Display::updateDeath(int name){
  mvwprintw(dialoguewin, this->yshift, 1, "%d has been killed", name);
  wrefresh(dialoguewin);
  set_yshift(yshift + 1);
}

void Display::updateAvatarHUD(std::string name){
  mvwprintw(avatarwin, 1, 1, "%s", player.get_name());
  mvwprintw(avatarwin, 2, 1, "%d/%d", player.get_health(), player.get_MAXhealth());
  mvwprintw(avatarwin, 3, 1, "%d/%d", player.get_mana(), player.get_MAXmana());
  mvwprintw(avatarwin, 4, 1, "%d", player.get_attack());
  mvwprintw(avatarwin, 5, 1, "%d", player.get_defense());
  wrefresh(avatarwin);

}

void Display::updateEnemyHUD(unsigned char tier){
  mvwprintw(enemywin, 1, 1, "%s", enemy.get_name());
  mvwprintw(enemywin, 2, 1, "%d/%d", enemy.get_health(), enemy.get_MAXhealth());
  mvwprintw(enemywin, 3, 1, "%d", enemy.get_mana());
  mvwprintw(enemywin, 4, 1, "%d", enemy.get_attack());
  mvwprintw(enemywin, 5, 1, "%d", enemy.get_defense());
  wrefresh(enemywin);
}

void Display::updateOptions(){
  wclear(optionwin);
  wrefresh(optionwin);
  keypad(optionwin, true);
  switch(this->selecter)
  {
    case 1:
    //Spells Options
    string Option1[4] = {"Attack", "Skills", "Flee", "Quit"};
    int choice1;
    int highlight1 = 0;

    while(1)
    {
        for(int i = 0; i < 4; i++)
        {
            if(i == highlight1)
                wattron(optionwin, A_REVERSE);
            mvwprintw(optionwin, i+1, 1, Option1[i].c_str());
            wattroff(optionwin, A_REVERSE);
        }
        choice1 = wgetch(optionwin);

        switch(choice1)
        {
            case KEY_UP:
                highlight1--;
                if(highlight1 == -1)
                    highlight1 = 0;
                break;
            case KEY_DOWN:
                highlight1++;
                if(highlight1 == 4)
                    highlight1 = 3;
                break;
            default:
                break;
        }
        if(choice1 == 10)
            break;
        }
        //Attack with basic damage
        if(Option1[highlight1] == Option1[0])
        {
          break;
        }
        //Go to spells selector
        else if(Option1[highlight1] == Option1[1])
        {
          set_selecter(2);
          break;
        }
        //Flee, stay in first selector
        else if(Option1[highlight1] == Option1[2])
        {
          break;
        }
        //Kill yourself and quits the game
        else if(Option1[highlight1] == Option1[3])
        {
          endwin();
          break;
        }

        case 2:
        //Spells Options
        string Option2[5] = {"Spell 1", "Spell 2", "Spell 3", "Spell 4", "Back"};
        int choice2;
        int highlight2 = 0;

        while(1)
        {
            for(int i = 0; i < 5; i++)
            {
                if(i == highlight2)
                    wattron(optionwin, A_REVERSE);
                mvwprintw(optionwin, i+1, 1, Option2[i].c_str());
                wattroff(optionwin, A_REVERSE);
            }
            choice2 = wgetch(optionwin);

            switch(choice2)
            {
                case KEY_UP:
                    highlight2--;
                    if(highlight2 == -1)
                        highlight2 = 0;
                    break;
                case KEY_DOWN:
                    highlight2++;
                    if(highlight2 == 5)
                        highlight2 = 4;
                    break;
                default:
                    break;
            }
            if(choice2 == 10)
                break;
            }
            //Attack with spell 1 stay in spell selecter
            if(Option2[highlight2] == Option2[0])
            {
              break;
            }
            //Attack with spell 1 stay in spell selecter
            else if(Option2[highlight2] == Option2[1])
            {
              break;
            }
            //Attack with spell 1 stay in spell selecter
            else if(Option2[highlight2] == Option2[2])
            {
              break;
            }
            //Attack with spell 1 stay in spell selecter
            else if(Option2[highlight2] == Option2[3])
            {
              break;
            }
            //Go back to first selecter
            else if(Option2[highlight2] == Option2[4])
            {
              set_selecter(1);
              break;
            }

  case 3:
  //Spells Options
  string Option3[5] = {"Spell 1", "Spell 2", "Spell 3", "Spell 4", "Back"};
  int choice3;
  int highlight3 = 0;

  while(1)
  {
      for(int i = 0; i < 5; i++)
      {
          if(i == highlight3)
              wattron(optionwin, A_REVERSE);
          mvwprintw(optionwin, i+1, 1, Option3[i].c_str());
          wattroff(optionwin, A_REVERSE);
      }
      choice3 = wgetch(optionwin);

      switch(choice3)
      {
          case KEY_UP:
              highlight3--;
              if(highlight3 == -1)
                  highlight3 = 0;
              break;
          case KEY_DOWN:
              highlight3++;
              if(highlight3 == 5)
                  highlight3 = 4;
              break;
          default:
              break;
      }
      if(choice3 == 10)
          break;
      }
      if(Option3[highlight3] == Option3[0])
        //attack with spell1
      else if(Option3[highlight3] == Option3[1])

      else if(Option3[highlight3] == Option3[2])

      else if(Option3[highlight3] == Option3[3])

      else if(Option3[highlight3] == Option3[4])

    }

  }

      //Getters
      int Display::get_yshift() {return yshift;}
      int Display::get_selecter() {return selecter;}

      //Setters
      void Display::set_yshift(int y) {yshift = y;}
      void Display::set_selecter(int s) {selecter = s;}
