#include <ncurses.h>
#include "displayOptions.hpp"
#include <iostream>
#include <string>
#include <vector>
//#include "Spell.hpp"
//#include "Player.hpp"
using namespace std;

int drawOptionDisplay(int yMax_, int xMax_, int classChoice) {
  int yMax = yMax_;
  int xMax = xMax_;
  int selecter = 1;

  //make box for options
  WINDOW * optionwin = newwin(yMax-1, xMax/2, yMax-11, 1);
  box(optionwin, 0, 0);
  refresh();
  wrefresh(optionwin);

  keypad(optionwin, true);
  while(selecter == 1 || selecter == 2){
  werase(optionwin);
  box(optionwin, 0, 0);
  switch(selecter)
  {
    case 1:
    {
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
        wrefresh(optionwin);
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
          return 5;
          selecter = 0;
        }
        //Go to spells selector
        else if(Option1[highlight1] == Option1[1])
        {
          selecter = 2;
        }
        //Flee, stay in first selector
        else if(Option1[highlight1] == Option1[2])
        {
          selecter = 1;
        }
        //Kill yourself and quits the game
        else if(Option1[highlight1] == Option1[3])
        {
          endwin();
        }
      }
        break;
        case 2:
        {
        /*//Spells Options
        for(unsigned int i = 0; i < temp.size(); i++)
        {
          Option2[i] = temp[i].get_name();
        }*/
        string Option2[5] = {"a", "b", "c", "d", "e"};
        //Option2[5] = "Back";
        /*string Option2[5] = {"Spell 1", "Spell 2", "Spell 3", "Spell 4", "hi"};
        if(classChoice == 1)//Warrior spells
        {
          std::cout << "hi" << endl;
          string Option2[5] = {"Spell 1", "Spell 2", "Spell 3", "Spell 4", "Back"};
        }
        else { //Mage spells
          std::cout << "hilo" << endl;
          string Option2[5] = {"Spell 1", "Spell 2", "Spell 3", "Spell 4", "Back"};
        }*/
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
            wrefresh(optionwin);
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
              return 1;
            }
            //Attack with spell 2 stay in spell selecter
            else if(Option2[highlight2] == Option2[1])
            {
              return 2;
            }
            //Attack with spell 3 stay in spell selecter
            else if(Option2[highlight2] == Option2[2])
            {
              return 3;
            }
            //Attack with spell 4 stay in spell selecter
            else if(Option2[highlight2] == Option2[3])
            {
              return 4;
            }
            //Go back to first selecter
            else if(Option2[highlight2] == Option2[4])
            {
              selecter = 1;
            }
          }
						default:
							throw "not an option";
    }//end of switch(selecter) statment
  }//end of while(selecter == 1 || selecter ==2)
}
