#include <ncurses.h>
#include <string>
#include <iostream>
//#include "game.hpp"
//#include "display.hpp"
using namespace std;

int main(int argc, char ** argv)
{
    //NCURSES START
    initscr();
    noecho();
    cbreak();

    //get screen size
    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    //create title window for game
    WINDOW * titlewin = newwin(yMax-12, xMax-1, 1, 1);
    box(titlewin, 0, 0);
    mvwprintw(titlewin, (yMax-12)/2, (xMax-6)/2, "SOUL QUEST");
    refresh();
    wrefresh(titlewin);

    //create a menu window for input
    WINDOW * menuwin = newwin(yMax-1, xMax-1, yMax-11, 1);
    box(menuwin, 0, 0);
    refresh();
    wrefresh(menuwin);

    //allows use of arrow keys
    keypad(menuwin, true);

    string startMenu[2] = {"New Game", "Exit Game"};
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
        //start game
       // while(game.is_running())
    }
        //start game

    else
    //deallocates memory and ends ncurses
    endwin();
    endwin();

    return 0;
}
