#include <ncurses.h>
#include <string>
#include <iostream>
#include <ctime>
#include "displayMenu.hpp"
#include "displayChar.hpp"
#include "displayOptions.hpp"

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
	int state = 0;
	while (state == 0) {
		state = drawMenuDisplay(yMax, xMax);
	}
  pair<int, string> chInput;
	while (state == 1) {
		chInput = drawCharDisplay(yMax, xMax);
    if(chInput.first == 1)
      state = chInput.first + 2;
    else
      state = chInput.first + 1;
    //Construct player
    //Player();
	}
  int spellChoice = drawOptionDisplay(yMax, xMax, chInput.first);

	endwin();
	cout << state << endl;
  cout << chInput.second << endl;
}
