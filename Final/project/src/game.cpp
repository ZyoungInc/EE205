#include "game.hpp"
#include <curses.h>
#include <ncurses.h>
#include <iostream>

using namespace std;

Game::Game() : {cout << "constructor" << endl;}

Game::~Game(){
  cout << "destructor" << endl;
}
void Game::createPlayer()
{
  clear();
  mvprintw(stdscr, 1, 1, "What is your name: ");
  Player.set_name() = getch();
  refresh();
  mvprintw(stdscr, 2, 1, "What class would you like to play? (Warrior/Mage): ");
  Player.set_class() = getch();
  refresh();

  Player player(Player.get_name(), Player.get_class(), Player.get_health(),
              Player.get_mana(), Player.get_attack(), Player.get_defense());
}
bool Game::is_running(void)
{
  Display.drawGame();
  Display.updateDialogue();
  while(!Combat.is_dead()){
    Display.updateOptions()
    attack_other()
    on_attack()
    attack_other()
    on_attack()
  }

  cout << "End of the game" << endl;
  return false;
}

bool Game::getInput(char *c)
{
  nodelay(stdscr, TRUE);
  if(*c == getch() == ERR)
  {
    return true;
  }
  *c = getch();
  return false;
}
