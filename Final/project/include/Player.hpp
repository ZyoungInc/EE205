#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Weapon.hpp"
#include "Spells.hpp"

using namespace std;

class Player {
protected:
		std::string name;
		std::string weapon_Type;
		std::string elemental_Type;
		std::string spellName;
		int health;
	  int MAXhealth;
	  int mana;
	  int MAXmana;
	  int attack;
	  int defense;
		Weapon *weap;

public:
		Player(); //Constructor
		~Player(); //Destructor
		Player(std::string name_, unsigned int classChoice, Weapon *weap_); //Overloaded Constructor
		//Player(const Player& other); //copy constructor
		//Player(Player&& other); //move constructor
		//Composition of Spells
		Spell cast;

		std::pair<int, int> cast_spell(unsigned int classChoice, unsigned int spellChoice, int atk);
		//Getters
		std::string get_name();
		std::string get_weapType();
		std::string get_eleType();
		std::string get_spellName();
		int get_health();
		int get_MAXhealth();
		int get_mana();
		int get_MAXmana();
		int get_attack();
		int get_defense();

		//Setters
		void set_name(std::string s);
		void set_spellName(std::string s);
		//void set_rarity(std::string r);
		//void set_type(std::string t);
		void set_health(int hp);
		void set_MAXhealth(int hp);
		void set_mana(int mp);
		void set_MAXmana(int mp);
		void set_attack(int atk);
   	void set_defense(int d);
		void set_weapType(std::string w);
		void set_eleType(std::string e);
};
#endif //PLAYER_HPP
