#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "combat.hpp"
#include "unit.hpp"
#include "Enemy.hpp"
//#include "Player.hpp"
#include "display.hpp"
#include "game-utility.hpp"

Combat::Combat(Unit& unit_, Display& display_, int kills_, int action_) :
  Unit(unit_),
  Display(display_),
  kills(kills_),
  action(action_) {}

void Combat::combat_phase(Player& player, Enemy& enemy)
{
  while(!player.is_dead() && !enemy.is_dead())
  {
    set_action(display.updateOptions());

    if(this->action == "Attack")
      player.attack_other(enemy);
    else if(this->action == "Spells"){
      set_action(display.updateOptions());

    }
    if(enemy.is_dead()) {}
    else {enemy.attack_other(player);}
  }

}

//Getters
int Combat::get_kills() {return kills;}
std::string Combat::get_action() {return action;}

//setters
void Combat::set_kills(int k) {this->kills = k;}
void Combat::set_action(std::string a) {this->action = a;}
