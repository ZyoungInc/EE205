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
#include "displayEvent.hpp"
#include "GameLoop.hpp"

using namespace std;

int main() {
	//NCURSES START
    initscr();
    noecho();
    cbreak();

	srand(time(NULL));//seeds rng
	//get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

	//Run game menu to get user's choice
	int state = 0; //use to track game's state
	pair<int, string> chInput;

  state = drawMenuDisplay(yMax, xMax);//displays title screen and ask if you want to play
  while(state == 1){
    GameLoop runGame(state, chInput, yMax, xMax);
    state = drawMenuDisplay(yMax, xMax);//displays title screen and ask if you want to play
  }
  
  endwin();//deallocates window memory
	return 0;//clean exit
}
