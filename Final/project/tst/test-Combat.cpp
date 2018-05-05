#include <iostream>
#include <string>
#include <utility>
#include <ctime>
#include <cstdlib>
#include <ncurses.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "game-utility.hpp"
#include "Weapon.hpp"
#include "Color.hpp"
#include "Combat.hpp"
#include "Spells.hpp"
#include "displayMenu.hpp"
#include "displayChar.hpp"
#include "displayDialogue.hpp"
#include "displayOptions.hpp"
#include "displayEnemyHUD.hpp"
#include "displayPlayerHUD.hpp"

using namespace std;

int main() {
  //NCURSES START
    initscr();
    noecho();
    cbreak();
	unsigned int randomNum;
	//int flag = 0;
	//char input = '0';
	srand(time(0));
  //get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

  //Run game menu to get user's choice
	int state = 0; //use to track game's state
	pair<int, string> chInput;

	state = drawMenuDisplay(yMax, xMax);

	while (state == 1) {
  	int stage = 1; //use to track player's tier level
    int souls = 0; //use to track how many kills player has
		chInput = drawCharDisplay(yMax, xMax);
    Weapon weap;
    randomNum = RandNum(1, 6);
    displayOpeningDiag(yMax, xMax);
    while(stage < 7)
    {
		if(chInput.first == 1)
    {
			state = chInput.first + 2;
      weap = Warrior_Weap(stage);
    }
		else
    {
			state = chInput.first + 1;
      weap = Mage_Weap(stage);
    }
		//Construct player
    Player p(chInput.second, chInput.first, souls, &weap);

	drawPlayerDisplay(yMax, xMax, chInput.second, chInput.first, p, weap);

    randomNum = RandNum(1, 6);
	  Enemy e(stage);
    drawEnemyDisplay(yMax, xMax, e);
    Combat battle(&p, &e, yMax, xMax);

	while(state != 1) {
		state = drawOptionDisplay(yMax, xMax, chInput.first);
		if(state == 1)//quit command
    {
      stage = 7;
			break;
    }
		else if(state == 7 && RandNum(1,4) == 2)
			//Flee command only work 25%
			break;
		else {
			state = battle.combat_phase(state, chInput.first, &p, &e);

			drawPlayerDisplay(yMax, xMax, chInput.second, chInput.first, p, weap);

			drawEnemyDisplay(yMax, xMax, e);
		}
		if(state == 1)//Enemy died
    {
      if(stage == 6)
      {
        displayEndingDiag(yMax, xMax);
        stage++;
        break;
      }
      else
      {
        souls++;
        if(souls > 4)
        {
          if(displayStageDiag(yMax, xMax, stage) == true)
          {
            stage++;
            souls = 0;
          }
        }
			   break;
      }
    }
    else if(state == 2)//Player died
    {
      displayDeathDiag(yMax, xMax);
      stage = 7;
      break;
    }
	}
  if(stage == 7)
    break;
}
	state = drawMenuDisplay(yMax, xMax);
	}

	endwin();
	return 0;
}
