#include <ncurses.h>
#include "displayChar.hpp"
#include <string>
#include <iostream>
#include <utility>

using namespace std;

pair<int, string> drawCharDisplay(int yMax_, int xMax_) {
	int yMax = yMax_;
	int xMax = xMax_;

	clear();
	char name[80];

	mvwprintw(stdscr, 1, 1, "What is your name: ");
	getstr(name);
	mvwprintw(stdscr, 1, 20, name);
	wrefresh(stdscr);
	
	//create a menu window for input
	WINDOW * classwin = newwin(7, xMax - 1, 4, 1);
	refresh();
	wrefresh(classwin);
	//allows use of arrow keys
	keypad(classwin, true);

	string classSelect[2] = {"Warrior", "Mage"};
	int choice;
	int highlight = 0;
	while(1)
	{
		mvwprintw(stdscr, 3, 1, "What class would you like to play? : ");
		wrefresh(stdscr);

		for(int i = 0; i < 2; i++)
		{
			if(i == highlight)
				wattron(classwin, A_REVERSE);
			mvwprintw(classwin, i+1, 1, classSelect[i].c_str());
			wattroff(classwin, A_REVERSE);
		}
		wrefresh(classwin);
		choice = wgetch(classwin);

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
	if(classSelect[highlight] == classSelect[0])
	{
		pair <int, string> temp_state;
		temp_state.first = 1;
		temp_state.second = name;
		return temp_state;
	}
	else if(classSelect[highlight] == classSelect[1])
	{
		pair <int, string> temp_state;
		temp_state.first = 2;
		temp_state.second = name;
		return temp_state;
	}
	else {
		throw "An error happened in displayChar";
	}
}
