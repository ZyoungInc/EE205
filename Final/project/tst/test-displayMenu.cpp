#include <ncurses.h>
#include <string>
#include <iostream>
#include "displayMenu.hpp"

using namespace std;

int main() {
	
	//NCURSES START
    initscr();
    noecho();
    cbreak();
	
	//get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);
	
	//Run game menu to get user's choice
	int inMenu = 0;
	while (inMenu == 0) {
		inMenu = drawMenuDisplay(yMax, xMax);
	}
	
	endwin();
}