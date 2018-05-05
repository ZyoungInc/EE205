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
	int stage = 1; //use to track player's tier level
	pair<int, string> chInput;

	state = drawMenuDisplay(yMax, xMax);

	while (state == 1) {

		chInput = drawCharDisplay(yMax, xMax);
    Weapon weap;
    randomNum = RandNum(1, 6);
		if(chInput.first == 1)
    {
			state = chInput.first + 2;
      weap = Warrior_Weap(randomNum);
    }
		else
    {
			state = chInput.first + 1;
      weap = Mage_Weap(randomNum);
    }
		//Construct player
    Player p(chInput.second, chInput.first, &weap);

	displayOpeningDiag(yMax, xMax);

  drawPlayerDisplay(yMax, xMax, chInput.second, chInput.first, p, weap);

    randomNum = RandNum(1, 6);
		Enemy e(randomNum);
    drawEnemyDisplay(yMax, xMax, e);
    Combat battle(&p, &e, yMax, xMax);
  while(state != 1)
  {
    state = drawOptionDisplay(yMax, xMax, chInput.first);
    if(state == 1)
      break;
    else if(state == 7 && RandNum(1,4) == 2)
        break;
    else
    {
      state = battle.combat_phase(state, chInput.first, &p, &e);

      drawPlayerDisplay(yMax, xMax, chInput.second, chInput.first, p, weap);

      drawEnemyDisplay(yMax, xMax, e);
    }
    if(state == 1)
      break;
  }
  state = drawMenuDisplay(yMax, xMax);
}
  endwin();
  return 0;
}
