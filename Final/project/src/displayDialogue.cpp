#include <ncurses.h>
#include "displayDialogue.hpp"
#include <string>
#include "Weapon.hpp"
#include "displayColor.hpp"

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
		mvwprintw(titlewin, 5, 5, "by the Demon. In the distance you can see monsters converging on you. What will");
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
		//werase(menuwin);
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
		mvwprintw(titlewin, 7, 5, "Have you truely beaten the game?");
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

bool displayStageDiag(int yMax_, int xMax_, int stage) {

	int yMax = yMax_;
	int xMax = xMax_;

	//create ask window for game
	WINDOW * askwin = newwin(yMax-12, xMax-1, 1, 1);
		box(askwin, 0, 0);
		mvwprintw(askwin, 2, 5, "Gate Guardian: I see you have collected many souls,");
		mvwprintw(askwin, 3, 5, "give them to me and I will grant you passage further into the depths of hell");
		refresh();
		wrefresh(askwin);

		//create a menu window for input
    WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    //allows use of arrow keys
    keypad(menuwin, true);

    string startMenu[2] = {"Yes", "No"};
    int choice;
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i < 2; i++)
        {
            if(i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, (xMax/2), startMenu[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if(highlight == -1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == 2)
                    highlight = 1;
                break;
            default:
                break;
        }
        if(choice == 10)
            break;
	}

    if(startMenu[highlight] == startMenu[0])
    {
			//create title window for game
			WINDOW * titlewin = newwin(yMax-12, xMax-1, 1, 1);
				start_color();
				GREENBLACK;
				wbkgd(titlewin, COLOR_PAIR(2));
		    box(titlewin, 0, 0);
		    mvwprintw(titlewin, 2, 5, "You have cleared stage %d" , stage);
				attroff(COLOR_PAIR(2));
		    refresh();
		    wrefresh(titlewin);

		    //create a menu window for input
		    WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
		    box(menuwin, 0, 0);
				mvwprintw(menuwin, 3, (xMax/2), "Press any key to continue");
		    refresh();
		    wrefresh(menuwin);

		    getchar();
        return true;
    }
    else
	{
		return false;
	}

}

void displayDeathDiag(int yMax_, int xMax_) {

	int yMax = yMax_;
	int xMax = xMax_;

	//create title window for game
	WINDOW * titlewin = newwin(yMax-12, xMax-1, 1, 1);
		start_color();
		box(titlewin, 0, 0);
		REDBLACK;
		wbkgd(titlewin, COLOR_PAIR(1));
    mvwprintw(titlewin, 2, 5, "Game over, You've died");
		attroff(COLOR_PAIR(1));
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

bool displayWeaponDrop(int yMax_, int xMax_, Weapon w) {
	int yMax = yMax_;
	int xMax = xMax_;

	//create ask window for game
	WINDOW * askwin = newwin(yMax-12, xMax-1, 1, 1);
		box(askwin, 0, 0);
		start_color();
		MAGENTABLACK;
		wbkgd(askwin, COLOR_PAIR(5));
		mvwprintw(askwin, 2, 5, "You have found a %s %s %s,", w.get_rarity().c_str(), w.get_element().c_str(), w.get_type().c_str());
		mvwprintw(askwin, 3, 5, "would you like to equip this weapon instead?");
		mvwprintw(askwin, 5, 5, "Name: %s %s %s", w.get_rarity().c_str(), w.get_element().c_str(), w.get_type().c_str());
		mvwprintw(askwin, 6, 5, "HP: %d", w.get_MAXhealth());
		mvwprintw(askwin, 7, 5, "MP: %d", w.get_MAXmana());
	  mvwprintw(askwin, 8, 5, "ATK: %d", w.get_wdamage());
	  mvwprintw(askwin, 9, 5, "DEF: %d", w.get_wdefense());
		attroff(COLOR_PAIR(5));

		refresh();
		wrefresh(askwin);

		//create a menu window for input
    WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    //allows use of arrow keys
    keypad(menuwin, true);

    string startMenu[2] = {"Yes", "No"};
    int choice;
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i < 2; i++)
        {
            if(i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, (xMax/2), startMenu[i].c_str());
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch(choice)
        {
            case KEY_UP:
                highlight--;
                if(highlight == -1)
                    highlight = 0;
                break;
            case KEY_DOWN:
                highlight++;
                if(highlight == 2)
                    highlight = 1;
                break;
            default:
                break;
        }
        if(choice == 10)
            break;
	}

    if(startMenu[highlight] == startMenu[0])
    {
        return true;
    }
    else
	{
		return false;
	}
}
