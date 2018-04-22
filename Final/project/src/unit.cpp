#include "unit.hpp"

// Constructs a unit with unit Variables
Unit::Unit(std::string name_,
      int health_,
      int mana_,
      int attack_,
      int defense_) :
    name(name_),
    health(health_),
    mana(mana_),
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
int Unit::get_mana() const {return mana;}
int Unit::get_attack() const {return attack;}
int Unit::get_defense() const {return defense;}

//Setters
void Unit::set_name(std::string s) { name = s;}
void Unit::set_health(int hp) {health = hp;}
void Unit::set_mana(int mp) {mana = mp;}
void Unit::set_attack(int atk) {attack = atk;}
void Unit::set_defense(int def) {defense = def;}
