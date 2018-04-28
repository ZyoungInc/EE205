#include "game.hpp"
#include "player.hpp"
#include <curses.h>
#include <ncurses.h>
#include <iostream>

using namespace std;

Game::Game() :  {cout << "constructor" << endl;}

Game::~Game(){
  cout << "destructor" << endl;
}
void Game::createPlayer()
{
  clear();
  char name[50];
  while(1){
  mvprintw(stdscr, 1, 1, "What is your name: ");
  while(getch() != 10)
  {
    name += getch();
  }
    refresh();
    player.set_name(name);

  }
  //create a menu window for input
  WINDOW * classwin = newwin(4, xMax-1, 7, 1);
  refresh();
  wrefresh(classwin);
  //allows use of arrow keys
  keypad(classwin, true);

  string classSelect[2] = {"Warrior", "Mage"};
  int choice;
  int highlight = 0;
  while(1)
  {
    mvprintw(stdscr, 3, 1, "What class would you like to play? : ");
      for(int i = 0; i < 2; i++)
      {
          if(i == highlight)
              wattron(classwin, A_REVERSE);
          mvwprintw(classwin, i+4, 1, startMenu[i].c_str());
          wattroff(classwin, A_REVERSE);
      }
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
        player.set_class("Warrior");
      if(classSelect[highlight] == classSelect[1])
        player.set_class("Mage");

}
bool Game::is_running(void)
{
  createPlayer();
  Display.drawGame();
  Display.updateDialogue();



  cout << "End of the game" << endl;
  return false;
}
