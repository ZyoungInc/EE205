#include <ncurses.h>
#include "displayEvent.hpp"
#include "Player.hpp"
#include "game-utility.hpp"
#include "Weapon.hpp"

bool drawRandomEvent(int yMax_, int xMax_) {
	int yMax = yMax_; 
	int xMax = xMax_;
	
	//create diaglog window 
	WINDOW * titlewin = newwin(yMax-12, xMax-1, 1, 1);
    box(titlewin, 0, 0);
	mvwprintw(titlewin, 2, 5, "You find yourself at a fork in the road");
	mvwprintw(titlewin, 3, 5, "1. To the left you see a dark path");
	mvwprintw(titlewin, 4, 5, "2. To the right you hear random noise, clearly an occupied room");
    refresh();
    wrefresh(titlewin);

    //create a menu window for input
    WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    //allows use of arrow keys
    keypad(menuwin, true);

    string startMenu[2] = {"1. To the left you see a dark path", "2. To the right you hear random noise, clearly an occupied room"};
    int choice;
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i < 2; i++)
        {
            if(i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, startMenu[i].c_str());
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

int drawHealEvent(int yMax_, int xMax_, Player *p) {
	int yMax = yMax_; 
	int xMax = xMax_;
	
	//create diaglog window 
	WINDOW * titlewin = newwin(yMax-12, xMax-1, 1, 1);
    box(titlewin, 0, 0);
	mvwprintw(titlewin, 2, 5, "A white robed figure approaches you an ask");
	mvwprintw(titlewin, 3, 5, "you look rough, I could patch you up...for a price");
	mvwprintw(titlewin, 4, 5, "ohh and don't try to scam me, I'm watching you");
    refresh();
    wrefresh(titlewin);

    //create a menu window for input
    WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    //allows use of arrow keys
    keypad(menuwin, true);

    string startMenu[2] = {"1. Heal for 40% (3 souls)", "2. No thanks (walk away)"};
    int choice;
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i < 2; i++)
        {
            if(i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, startMenu[i].c_str());
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
		if(p->get_souls() >= 3) {
			p->set_souls(p->get_souls() - 3);
			p->set_health((p->get_health() * .6));
			wclear(titlewin);
			box(titlewin, 0, 0);
			mvwprintw(titlewin, 2, (xMax/2)-11, "You were healed");
			refresh();
			wrefresh(titlewin);
		}
		else {
			p->set_health(-1*(p->get_health() * .6));
			wclear(titlewin);
			mvwprintw(titlewin, 2, (xMax/2)-11, "You paid a terrible price");
			box(titlewin, 0, 0);
			refresh();
			wrefresh(titlewin);
		}
        
    }
	
	wclear(menuwin);
	box(menuwin, 0, 0);
	mvwprintw(menuwin, 2, (xMax/2)-11, "press any key to continue");
	wrefresh(menuwin);
	getchar();
	return 0;
}

int drawBeggerEvent(int yMax_, int xMax_, Player *p) {
	int yMax = yMax_; 
	int xMax = xMax_;
	
	//create diaglog window 
	WINDOW * titlewin = newwin(yMax-12, xMax-1, 1, 1);
    box(titlewin, 0, 0);
	mvwprintw(titlewin, 2, 5, "A begger extend his hand and begs for souls");
    refresh();
    wrefresh(titlewin);

    //create a menu window for input
    WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    //allows use of arrow keys
    keypad(menuwin, true);

    string startMenu[2] = {"1. give him a soul", "2. walk away"};
    int choice;
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i < 2; i++)
        {
            if(i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, startMenu[i].c_str());
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
		if(p->get_souls() >= 1) {
			p->set_souls(p->get_souls() - 1);
			wclear(titlewin);
			box(titlewin, 0, 0);
			mvwprintw(titlewin, 2, 5, "Thank you kind wander");
			refresh();
			wrefresh(titlewin);
		}
		else {
			wclear(titlewin);
			box(titlewin, 0, 0);
			mvwprintw(titlewin, 2, (xMax/2)-11, "The beggar grabs your weapon and runs away");
			refresh();
			wrefresh(titlewin);
			Weapon weap;
			p->swap_weapon(&weap);
		}
    }
	else {
		//percent chance
		int randnum = RandNum(1,100);
		if(randnum <= 10) {
			wclear(titlewin);
			box(titlewin, 0, 0);
			mvwprintw(titlewin, 2, (xMax/2)-11, "The beggar grabs your weapon and runs away");
			refresh();
			wrefresh(titlewin);
			Weapon weap;
			p->swap_weapon(&weap);
		}
	}
	
	wclear(menuwin);
	box(menuwin, 0, 0);
	mvwprintw(menuwin, 2, 1, "press any key to continue");
	wrefresh(menuwin);
	getchar();
	return 0;
}

int drawLootEvent(int yMax_, int xMax_, Player *p) {
	int yMax = yMax_; 
	int xMax = xMax_;
	bool got_loot = false;
	
	//create diaglog window 
	WINDOW * titlewin = newwin(yMax-12, xMax-1, 1, 1);
    box(titlewin, 0, 0);
	mvwprintw(titlewin, 2, 5, "A Chest with a trap in it, a soul will open the box");
    refresh();
    wrefresh(titlewin);

    //create a menu window for input
    WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    //allows use of arrow keys
    keypad(menuwin, true);

    string startMenu[2] = {"1. use a soul to open the chest", "2. walk away"};
    int choice;
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i < 2; i++)
        {
            if(i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, startMenu[i].c_str());
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
		if(p->get_souls() >= 1) {
			p->set_souls(p->get_souls() - 1);
			wclear(titlewin);
			box(titlewin, 0, 0);
			mvwprintw(titlewin, 2, 5, "The loot is yours for the taking");
			refresh();
			wrefresh(titlewin);
			got_loot = true;
		}
		else {
			p->set_health(p->get_health() * -.3);
			wclear(titlewin);
			box(titlewin, 0, 0);
			mvwprintw(titlewin, 2, (xMax/2)-11, "You triggered the trap, the weapon was destroyed");
			refresh();
			wrefresh(titlewin);
		}
    }
	
	wclear(menuwin);
	box(menuwin, 0, 0);
	mvwprintw(menuwin, 2, 1, "press any key to continue");
	wrefresh(menuwin);
	getchar();
	return got_loot;
}

int drawRestingEvent(int yMax_, int xMax_, Player *p) {
	int yMax = yMax_; 
	int xMax = xMax_;
	
	//create diaglog window 
	WINDOW * titlewin = newwin(yMax-12, xMax-1, 1, 1);
    box(titlewin, 0, 0);
	mvwprintw(titlewin, 2, 5, "You stumble upon a nice resting area");
	mvwprintw(titlewin, 3, 5, "You take a nice nap and feel refreshed");
    refresh();
    wrefresh(titlewin);
	
	p->set_health(p->get_health() * .4);
	

    //create a menu window for input
	WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
    box(menuwin, 0, 0);
	mvwprintw(menuwin, 3, (xMax/2), "Press any key to continue");
    refresh();
    wrefresh(menuwin);

    getchar();
	werase(menuwin);
	wrefresh(menuwin);
	return 0;// not sure 
}	
	
int drawTrapEvent(int yMax_, int xMax_, Player *p) {
	int yMax = yMax_; 
	int xMax = xMax_;
	
	//create diaglog window 
	WINDOW * titlewin = newwin(yMax-12, xMax-1, 1, 1);
    box(titlewin, 0, 0);
	mvwprintw(titlewin, 2, 5, "You stumble upon a nice resting area");
	mvwprintw(titlewin, 3, 5, "suddenly you feel the ground break under you ");
    refresh();
    wrefresh(titlewin);
	
	//create a menu window for input
    WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    //allows use of arrow keys
    keypad(menuwin, true);

    string startMenu[2] = {"1. Attempt to grab you weapon, taking damage in the process(30%)", "2. Avoid the hole, losing your weapon"};
    int choice;
    int highlight = 0;

    while(1)
    {
        for(int i = 0; i < 2; i++)
        {
            if(i == highlight)
                wattron(menuwin, A_REVERSE);
            mvwprintw(menuwin, i+1, 1, startMenu[i].c_str());
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
		p->set_health(p->get_health() * -.3 );
		wclear(titlewin);
		box(titlewin, 0, 0);
		mvwprintw(titlewin, 2, (xMax/2)-11, "You grab you weapon but you take fall damage");
		refresh();
		wrefresh(titlewin);
    }
	else {
		wclear(titlewin);
		box(titlewin, 0, 0);
		mvwprintw(titlewin, 2, (xMax/2)-11, "Your weapon fall throug the hole, but you avoid any damage");
		refresh();
		wrefresh(titlewin);
		Weapon weap;
		p->swap_weapon(&weap);
	}
	
	wclear(menuwin);
	box(menuwin, 0, 0);
	mvwprintw(menuwin, 2, (xMax/2)-11, "press any key to continue");
	wrefresh(menuwin);
	getchar();
	return 0;
}
	