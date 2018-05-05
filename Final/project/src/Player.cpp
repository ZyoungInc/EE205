#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include "game-utility.hpp"
#include "Player.hpp"
#include "Weapon.hpp"
#include "Spells.hpp"

using namespace std;

//Default Constructor
Player::Player() :
  name(""),
  //rarity(""),
  //type(""),
  MAXhealth(0),
  MAXmana(0),
	health(0),
	mana(0),
  attack(0),
  defense(0) {}

Player::~Player() {}

/* Constructs a Player with default stats and  chosen name */
Player::Player(string name_, unsigned int classChoice, Weapon *weap_) {
	this->name = name_;
	weap = weap_;
	this->MAXhealth = this->health = weap->get_MAXhealth();
	this->MAXmana = this->mana = weap->get_MAXmana();
  if(classChoice == 1)
    this->mana = 0;
	this->attack = weap->get_wdamage();
	this->defense = weap->get_wdefense();
  weapon_Type = weap->get_type();
}

  /*//Copy Constructor
  Player::Player(const Player& other) :
    name(other.name),
    health(other.health),
    mana(other.mana),
    attack(other.attack),
    defense(other.defense) {}
  //Move Constructor
  Player::Player(Player&& other) :
    name(move(other.name)),
    health(move(other.health)),
    mana(move(other.mana)),
    attack(move(other.attack)),
    defense(move(other.defense)) {}*/
    std::pair<int, int> Player::cast_spell(unsigned int classChoice, unsigned int spellChoice, int atk){
      vector<Spell> spellBook(MakeSpellBook(classChoice));
      int damage = atk * spellBook[spellChoice].get_damage();
      int hits = spellBook[spellChoice].get_hits();
      int cost = spellBook[spellChoice].get_cost();
      int heal = spellBook[spellChoice].check_Effect(atk);
      std::string eType = spellBook[spellChoice].get_EleType();
      std::string sName = spellBook[spellChoice].get_name();
      if(cost <= this->mana)
        set_mana(-1*cost);
      else
      {
        damage = atk;
        hits = 1;
        set_mana(20);
      }
      set_eleType(eType);
      set_spellName(sName);
      set_health(heal);

      std::pair<int, int> temp_cast_spell;
      temp_cast_spell.first = damage;
      temp_cast_spell.second = hits;
      return temp_cast_spell;
    }


   //Getters
    string Player::get_name() {return name;}
    string Player::get_weapType() {return weapon_Type;}
    string Player::get_eleType() {return elemental_Type;}
    string Player::get_spellName() {return spellName;}
    int Player::get_health() {return health;}
    int Player::get_MAXhealth() {return MAXhealth;}
    int Player::get_mana() {return mana;}
    int Player::get_MAXmana() {return MAXmana;}
    int Player::get_attack() {return attack;}
    int Player::get_defense() {return defense;}

  //Setters
    void Player::set_name(string s) {name = s;}
    //void Player::set_rarity(string r) {rarity = r;}
    //void Player::set_type(string t) {type = t;}
    void Player::set_health(int hp){
    if(hp + health > MAXhealth)
      health = MAXhealth;
      else if (health + hp < 0)
      health = 0;
    else
          health += hp;
  }
    void Player::set_MAXhealth(int hp){MAXhealth = hp;}
    void Player::set_mana(int mp){
    if (mp + mana > MAXmana)
  		mana = MAXmana;
      else if (mana + mp < 0)
  		mana = 0;
  	else
          mana += mp;
  }
    void Player::set_MAXmana(int mp){MAXmana = mp;}
    void Player::set_attack(int atk){attack = atk;}
    void Player::set_defense(int d){defense = d;}
    void Player::set_weapType(std::string w) {weapon_Type = w;}
    void Player::set_eleType(std::string e) {elemental_Type = e;}
    void Player::set_spellName(std::string s) {spellName = s;}
