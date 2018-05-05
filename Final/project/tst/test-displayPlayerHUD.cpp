#include <ncurses.h>
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Enemy.hpp"
#include "Player.hpp"
#include "Weapon.hpp"
#include "game-utility.hpp"
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

	//seed randnum
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
		if(chInput.first == 1)
    {
			state = chInput.first + 2;
      weap = Warrior_Weap(RandNum(1,6));
    }
		else
    {
			state = chInput.first + 1;
      weap = Mage_Weap(RandNum(1,6));
    }
		//Construct player
    //Warrior_Weap weap(RandNum(1,6));
    Enemy e(RandNum(1,6));
		Player p(chInput.second, &weap);


	displayOpeningDiag(yMax, xMax);

  drawPlayerDisplay(yMax, xMax, chInput.second, chInput.first, p, weap);

  drawEnemyDisplay(yMax, xMax, e);

  state = drawOptionDisplay(yMax, xMax, chInput.first);
  if(state != 1)
  {
	displayEndingDiag(yMax, xMax);

	displayStageDiag(yMax, xMax, stage);

	displayDeathDiag(yMax, xMax);
  }
	 state = drawMenuDisplay(yMax, xMax);

	}

	endwin();
	cout << state << endl;
	cout << chInput.second << endl;
}
