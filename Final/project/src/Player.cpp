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
	weapon_Type(""),
	health(0),
	MAXhealth(0),
	mana(0),
	MAXmana(0),
	attack(0),
	defense(0),
	souls(0) {}

Player::~Player() {}

/* Constructs a Player with default stats and  chosen name */
Player::Player(string name_, unsigned int classChoice, int souls_, Weapon *weap_) {
	this->name = name_;
	this->weap = weap_;
	//Player is gaining stats from weapon
	this->MAXhealth = this->health = weap->get_MAXhealth();
	this->MAXmana = weap->get_MAXmana();
	this->attack = weap->get_wdamage();
	this->defense = weap->get_wdefense();
	this->souls = souls_;
	this->weapon_Type = weap->get_type();
	this->rarity_Type = weap->get_rarity();
	if(classChoice == 1) {
		this->player_Class = "Warrior";
		this->mana = 0;//Warrior has rage
	}
	else {
		this->player_Class = "Mage";
		this->elemental_Type = weap->get_element();
		this->mana = weap->get_MAXmana();//Mage has mana
	}
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
	vector<Spell> spellBook(MakeSpellBook(classChoice, weapon_Type, elemental_Type));
	int damage = atk * spellBook[spellChoice].get_damage();
	int hits = spellBook[spellChoice].get_hits();
	int cost = spellBook[spellChoice].get_cost();
	int heal = spellBook[spellChoice].check_Effect(atk);
	std::string sName = spellBook[spellChoice].get_name();
	set_spellName(sName);
	set_health(heal);
	if(cost <= this->mana) {
		set_mana(-1*cost);
	}
	else
	{
		damage = 0;
		hits = 0;
		set_spellName("a failed spell");
	}

		std::pair<int, int> temp_cast_spell;
		temp_cast_spell.first = damage;
		temp_cast_spell.second = hits;
		return temp_cast_spell;
}


//Getters
string Player::get_name() {return this->name;}
string Player::get_weapType() {return this->weapon_Type;}
string Player::get_eleType() {return this->elemental_Type;}
string Player::get_spellName() {return this->spellName;}
string Player::get_Class() {return this->player_Class;}
string Player::get_rarity(){return this->rarity_Type;}
int Player::get_health() {return this->health;}
int Player::get_MAXhealth() {return this->MAXhealth;}
int Player::get_mana() {return this->mana;}
int Player::get_MAXmana() {return this->MAXmana;}
int Player::get_attack() {return this->attack;}
int Player::get_defense() {return this->defense;}
int Player::get_souls() {return this->souls;}

//Setters
void Player::set_name(string s) {this->name = s;}
//void Player::set_rarity(string r) {rarity = r;}
//void Player::set_type(string t) {type = t;}
void Player::set_health(int hp){
	if(hp + this->health > this->MAXhealth)
		this->health = this->MAXhealth;
	else if (health + hp < 0)
		this->health = 0;
	else
		this->health += hp;
}

void Player::swap_weapon(Weapon *weap_) {
	this->weap = weap_;
	this->attack = weap->get_wdamage();
	this->defense = weap->get_wdefense();
	if(this->get_Class() == "Mage"){
		if(this->mana < weap->get_MAXmana()) {
			//If the weapon increase your max mp, then increase your mp by the diffence
			this->mana += (weap->get_MAXmana() - this->MAXmana);
			if(this->mana < 0){
				this->mana = 0;
			}
		}
	}
	if(this->mana >= weap->get_MAXmana()) {
			//Edge case if you get healed over your MAXmana
			this->mana = weap->get_MAXmana();
	}
	this->MAXmana = weap->get_MAXmana();
	if(this->MAXhealth < weap->get_MAXhealth()) {
		//If the weapon increase your max hp, then increase your hp by the diffence
		this->health += (weap->get_MAXhealth() - this->MAXhealth);
	}
	if(this->health >= weap->get_MAXhealth()) {
			//Edge case if you get healed over your  MAXhealth
			this->health = weap->get_MAXhealth();
	}
	this->MAXhealth = weap->get_MAXhealth();
	this->weapon_Type = weap->get_type();
	this->elemental_Type = weap->get_element();
	this->rarity_Type = weap->get_rarity();
}

void Player::set_MAXhealth(int hp){MAXhealth = hp;}
void Player::set_mana(int mp){
if (mp + this->mana > this->MAXmana)
	this->mana = this->MAXmana;
else if (this->mana + mp < 0)
	this->mana = 0;
else
	this->mana += mp;
}

void Player::set_MAXmana(int mp){this->MAXmana = mp;}
void Player::set_attack(int atk){this->attack = atk;}
void Player::set_defense(int d){this->defense = d;}
void Player::set_weapType(std::string w) {this->weapon_Type = w;}
void Player::set_rarity(std::string r) {this->rarity_Type = r;}
void Player::set_eleType(std::string e) {this->elemental_Type = e;}
void Player::set_spellName(std::string s) {this->spellName = s;}
void Player::set_souls(int s) {this->souls = s;}
