#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <ncurses.h>
#include "Combat.hpp"
#include "Unit.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Spells.hpp"
//#include "display.hpp"
#include "game-utility.hpp"
#include "Weapon.hpp"

//Default Constructor
Combat::Combat() {}

//Destructor
Combat::~Combat() {}

//Overloaded Constructor
Combat::Combat(Player *p_, Enemy *e_, int yMax_, int xMax_)
{
  p = p_;
  e = e_;
  this->yMax = yMax_;
  this->xMax = xMax_;

  //create title window for game
	combatwin = newwin(yMax-12, xMax-1, 1, 1);
    box(combatwin, 0, 0);
    mvwprintw(combatwin, get_yshift(), 1, "You encounter a %s", e->get_name().c_str());
    set_yshift(1);
    refresh();
    wrefresh(combatwin);
}

int Combat::combat_phase(unsigned int action, int classPick, Player *p, Enemy *e)
  {
    float effect;

        effect = eff_calc_other(p->get_weapType(), p->get_eleType(),
                                e->get_wep_type(), e->get_element());
        player_attack(p, e, action, classPick, effect);
    if(e->get_health() > 0)
    {
      effect = eff_calc_other(e->get_wep_type(), e->get_element(),
                              p->get_weapType(), p->get_eleType());
      enemy_attack(p, e, effect);
    }
    if(e->get_health() == 0 || p->get_health() == 0)
      return 1;
    else
      return 2;
  }

float Combat::eff_calc_other(std::string atkWeap, std::string atkEle,
                          std::string defWeap, std::string defEle) {
  float effect = 1;
  //Element triange
  if(atkEle == "fire" && defEle == "nature") effect = 2;
  else if(atkEle == "fire" && defEle == "water") effect = 0.5;
  else if(atkEle == "water" && defEle == "fire") effect = 2;
  else if(atkEle == "water" && defEle == "nature") effect = 0.5;
  else if(atkEle == "nature" && defEle == "water") effect = 2;
  else if(atkEle == "nature" && defEle == "fire") effect = 0.5;
  //Weapon Triangle
  else if(atkWeap == "Sword" && defWeap == "Axe") effect = 2;
  else if(atkWeap == "Sword" && defWeap == "Lance") effect = 0.5;
  else if(atkWeap == "Lance" && defWeap == "Sword") effect = 2;
  else if(atkWeap == "Lance" && defWeap == "Axe") effect = 0.5;
  else if(atkWeap == "Axe" && defWeap == "Lance") effect = 2;
  else if(atkWeap == "Axe" && defWeap == "Sword") effect = 0.5;
  else effect = 1;

  return effect;

}
void Combat::player_attack(Player *p, Enemy *e, unsigned int action, int classPick, float effect) {
  int damage;
  if(action == 2)
  {
    damage = std::max(0, int(p->get_attack() * effect - e->get_defense()));
    p->set_mana(20);
    /*//testing
    mvwprintw(this->get_combatwin(), get_yshift(), 1, "You dealt %d damage to %s with basic attack", damage, e->get_name().c_str());
    set_yshift(1);
    wrefresh(this->get_combatwin());*/
  }
  else if(action == 7)
    damage = 0;
  else
  {
    std::pair<int, int> spellDamage = p->cast_spell(classPick, action-3, p->get_attack());
    damage = std::max(0, spellDamage.second * int(spellDamage.first * effect - e->get_defense()));
    /*mvwprintw(combatwin, get_yshift(), 1, "You dealt %d damage to %s with %s", damage, e->get_name().c_str(), p->get_spellName().c_str());
    set_yshift(1);
    wrefresh(combatwin);*/
  }
  e->set_health(-1 * damage);
  if (e->get_health() <= 0) {
    on_death();
  }
}

void Combat::enemy_attack(Player *p, Enemy *e, float effect){
  int damage = std::max(0, int(e->get_attack() * effect - p->get_defense()));
  p->set_health(-1 * damage);
  if (p->get_health() <= 0) {
    on_death();
  }
}

bool Combat::is_dead()  {
  return true;
}

void Combat::on_death(){
  is_dead();
  //Display Unit died
  //dialogue.set_yshift(dialogue.updateDeath(this->name));
  //if player unit is dead, end Game

  //counter for enemies_killed
  //set_souls(1);
}

//Getters
int Combat::get_souls() {return souls;}
int Combat::get_action() {return action;}
int Combat::get_yshift() {return yshift;}

//setters
void Combat::set_souls(int s) {souls += s;}
void Combat::set_action(int a) {action = a;}
void Combat::set_yshift(int y) {yshift += y;}
