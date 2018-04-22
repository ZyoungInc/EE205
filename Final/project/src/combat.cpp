#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "combat.hpp"
#include "unit.hpp"
//#include "Enemy.hpp"
#include "game-utility.hpp"

Combat::Combat(Unit& Unit_, Display& Display_) :
  Unit(Unit_),
  Display(Display_) {}

void attack_other(Unit& other) {
  int damage = std::max(0, this->Unit.get_attack() - Unit.other.get_defense());
  other.on_attack(damage);
}

void on_attack(int damage) {
  //Display damage feed
  set_yshift(Display.updateCombat());

  this->Unit.get_health() -= damage;

  if (this->Unit.get_health() <= 0) {
    on_death();
  }
}

bool is_dead() const {
  return this->Unit.get_health() <=0;
}

void on_death(){
  //Display Unit died
  set_yshift(Display.updateDeath());
  //if player unit is dead, end Game
}
