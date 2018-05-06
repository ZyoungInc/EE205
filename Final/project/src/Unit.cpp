#include <algorithm>
#include "Unit.hpp"
#include <string>

//Default constructor
Unit::Unit() :
    name(""),
	health(0),
    MAXhealth(0),// added max HP
	mana(0),
	MAXmana(0),
    attack(0),
    defense(0) {}

// Constructs a unit with unit Variables
Unit::Unit(std::string name_,
      int health_,
      int mana_,
      int attack_,
      int defense_) :
    name(name_),
	health(health_),
	MAXhealth(health_),// added max HP
	mana(mana_),
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
std::string Unit::get_name() {return name;}
int Unit::get_health() {return health;}
int Unit::get_MAXhealth()  {return MAXhealth;}
int Unit::get_MAXmana()  {return MAXmana;}
int Unit::get_mana()  {return mana;}
int Unit::get_attack()  {return attack;}
int Unit::get_defense()  {return defense;}

//Setters
void Unit::set_name(std::string s) { name = s;}
void Unit::set_health(int hp) {
	if (hp + health > MAXhealth)
		health = MAXhealth;
    else if (health + hp < 0)
		health = 0;
	else
        health += hp;
}
void Unit::set_MAXhealth(int hp) {MAXhealth = hp;}
void Unit::set_MAXmana(int mp) {
	if (mp + mana > MAXmana)
		mana = MAXmana;
    else if (mana + mp < 0)
		mana = 0;
	else
        mana += mp;
}
void Unit::set_mana(int mp) {mana = mp;}
void Unit::set_attack(int atk) {attack = atk;}
void Unit::set_defense(int def) {defense = def;}

/*void Unit::attack_other(Unit& other) {

  int damage = std::max(0, this->attack - other.defense);
  other.on_attack(damage);
}*/
/*void Unit::spell_other(Unit& other) {
  int damage = std::max(0, int(spell.damage * effect) - other.defense);
  other.on_attack(damage);
}* SPELL NOT WORKING ATM */

/*void Unit::on_attack(int damage) {
  //Display damage feed
  set_yshift(Display.updateCombat(this->health, damage));

  this->health -= damage;

  if (this->health <= 0) {
    on_death();
  }
}

bool Unit::is_dead()  {
  return this->health <=0;
}

void Unit::on_death(){
  //Display Unit died
  dialogue.set_yshift(dialogue.updateDeath(this->name));
  //if player unit is dead, end Game

  //counter for enemies_killed
  set_kills(this->kills);
} DISPLAY CLASS NOT WORKING ATM*/
