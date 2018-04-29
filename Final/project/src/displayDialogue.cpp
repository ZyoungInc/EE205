#include <ncurses.h>
#include "displayDialogue.hpp"
#include <string>

using namespace std;

void displayOpeningDiag(int yMax_, int xMax_) {

	int yMax = yMax_;
	int xMax = xMax_;

	//create title window for game
	WINDOW * titlewin = newwin(yMax-12, xMax-1, 1, 1);
    box(titlewin, 0, 0);
    mvwprintw(titlewin, 2, 5, "You awake in a dark, cold cave. Everything is a blur at first but you slowly regain");
	mvwprintw(titlewin, 3, 5, "your senses. Your beloved wife died in fire and you tried a forbidden ritual to");
	mvwprintw(titlewin, 4, 5, "try and bring her back from the underworld. Alas it was a trap! You are now trapped");
	mvwprintw(titlewin, 5, 5, "by the Demon. In the distance you can see monsters converging on you. What Will");
	mvwprintw(titlewin, 6, 5, "you do?");
    refresh();
    wrefresh(titlewin);

    //create a menu window for input
    WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
    box(menuwin, 0, 0);
	mvwprintw(menuwin, 3, (xMax/2), "Press any key to continue");
    refresh();
    wrefresh(menuwin);

    getchar();
		werase(menuwin);
		wrefresh(menuwin);

}


void displayEndingDiag(int yMax_, int xMax_) {

	int yMax = yMax_;
	int xMax = xMax_;

	//create title window for game
	WINDOW * titlewin = newwin(yMax-12, xMax-1, 1, 1);
    box(titlewin, 0, 0);
    mvwprintw(titlewin, 2, 5, "The demon has been defeated! You have reclaimed your wife and have returned");
	mvwprintw(titlewin, 3, 5, "to the surface. Now that all your troubles are over, you can finally know peace...");
	mvwprintw(titlewin, 4, 5, "or do you?");
	mvwprintw(titlewin, 7, 5, "Have have beaten the game!");
    refresh();
    wrefresh(titlewin);

    //create a menu window for input
    WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
    box(menuwin, 0, 0);
	mvwprintw(menuwin, 3, (xMax/2), "Press any key to continue");
    refresh();
    wrefresh(menuwin);

    getchar();
}

void displayStageDiag(int yMax_, int xMax_, int stage) {

	int yMax = yMax_;
	int xMax = xMax_;


	//create title window for game
	WINDOW * titlewin = newwin(yMax-12, xMax-1, 1, 1);
    box(titlewin, 0, 0);
    mvwprintw(titlewin, 2, 5, "You have cleared stage %d" , stage);
    refresh();
    wrefresh(titlewin);

    //create a menu window for input
    WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
    box(menuwin, 0, 0);
	mvwprintw(menuwin, 3, (xMax/2), "Press any key to continue");
    refresh();
    wrefresh(menuwin);

    getchar();
}

void displayDeathDiag(int yMax_, int xMax_) {

	int yMax = yMax_;
	int xMax = xMax_;

	//create title window for game
	WINDOW * titlewin = newwin(yMax-12, xMax-1, 1, 1);
    box(titlewin, 0, 0);
    mvwprintw(titlewin, 2, 5, "Game over, You've died" );
    refresh();
    wrefresh(titlewin);

    //create a menu window for input
    WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
    box(menuwin, 0, 0);
	mvwprintw(menuwin, 3, (xMax/2), "Press any key to continue");
    refresh();
    wrefresh(menuwin);

    getchar();
}
