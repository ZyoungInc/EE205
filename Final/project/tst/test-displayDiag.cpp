#include <ncurses.h>
#include <string>
#include <iostream>
#include <ctime>
#include "displayMenu.hpp"
#include "displayChar.hpp"
#include "displayDialogue.hpp"

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
		
		if(chInput.first == 1)
			state = chInput.first + 2;
		else
			state = chInput.first + 1;
		//Construct player
		//Player();
	
	
	displayOpeningDiag(yMax, xMax);
	
	displayEndingDiag(yMax, xMax);
	
	displayStageDiag(yMax, xMax, stage);
	
	displayDeathDiag(yMax, xMax);
	
	state = drawMenuDisplay(yMax, xMax);
	
	}
	
	endwin();
	cout << state << endl;
	cout << chInput.second << endl;
}
