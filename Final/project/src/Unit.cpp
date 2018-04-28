#include <algorithm>
#include "Unit.hpp"

//Default constructor
Unit::Unit() :
    name(""),
    health(0),
	MAXhealth(0),// added max HP
    mana(0),
    attack(0),
    defense(0) {}

// Constructs a unit with unit Variables
Unit::Unit(std::string name_,
      int MAXhealth_,
      int MAXmana_,
      int attack_,
      int defense_) :
    name(name_),
	MAXhealth(health_),// added max HP
    MAXmana(mana_),
    attack(attack_),
    defense(defense_) {}

// Copy Constructor
Unit::Unit(const Unit& other) :
  name(other.name),
  health(other.health),
  mana(other.mana),
  attack(other.attack),
  defense(other.defense) {}

//Move Constructor
Unit::Unit(Unit&& other) :
  name(std::move(other.name)),
  health(std::move(other.health)),
  mana(std::move(other.mana)),
  attack(std::move(other.attack)),
  defense(std::move(other.defense)) {}

//Getters
std::string Unit::get_name() const {return name;}
int Unit::get_health() const {return health;}
int Unit::get_MAXhealth() const {return Maxhealth;}
int Unit::get_MAXmana() const {return MAXmana;}
int Unit::get_mana() const {return mana;}
int Unit::get_attack() const {return attack;}
int Unit::get_defense() const {return defense;}

//Setters
void Unit::set_name(std::string s) { name = s;}
void Unit::set_health(int hp) {health = hp;}
void Unit::set_MAXhealth(int hp) {MAXhealth = hp;}
void Unit::set_MAXmana(int mp) {MAXmana = mp;}
void Unit::set_mana(int mp) {mana = mp;}
void Unit::set_attack(int atk) {attack = atk;}
void Unit::set_defense(int def) {defense = def;}

double Unit::eff_calc_other(std::pair<std::string, std::string> attacker,
                          std::pair<std::string, std::string> taker) {
  double effect = 1;
  //Element triange
  if(attacker.first == "fire" && taker.first == "nature") effect = 2;
  else if(attacker.first == "fire" && taker.first == "water") effect = 0.5;
  else if(attacker.first == "water" && taker.first == "fire") effect = 2;
  else if(attacker.first == "water" && taker.first == "nature") effect = 0.5;
  else if(attacker.first == "nature" && taker.first == "water") effect = 2;
  else if(attacker.first == "nature" && taker.first == "fire") effect = 0.5;
  //Weapon Triangle
  else if(attacker.second == "Sword" && taker.second == "Axe") effect = 2;
  else if(attacker.second == "Sword" && taker.second == "Lance") effect = 0.5;
  else if(attacker.second == "Lance" && taker.second == "Sword") effect = 2;
  else if(attacker.second == "Lance" && taker.second == "Axe") effect = 0.5;
  else if(attacker.second == "Axe" && taker.second == "Lance") effect = 2;
  else if(attacker.second == "Axe" && taker.second == "Sword") effect = 0.5;

  return effect;

}

void Unit::attack_other(Unit& other) {

  int damage = std::max(0, this->attack - other.defense);
  other.on_attack(damage);
}
void Unit::spell_other(Unit& other) {
  int damage = std::max(0, int(spell.damage * effect) - other.defense);
  other.on_attack(damage);
}

void Unit::on_attack(int damage) {
  //Display damage feed
  set_yshift(Display.updateCombat(this->health, damage));

  this->health -= damage;

  if (this->health <= 0) {
    on_death();
  }
}

bool Unit::is_dead() const {
  return this->health <=0;
}

void Unit::on_death(){
  //Display Unit died
  dialogue.set_yshift(dialogue.updateDeath(this->name));
  //if player unit is dead, end Game

  //counter for enemies_killed
  set_kills(this->kills);
}
