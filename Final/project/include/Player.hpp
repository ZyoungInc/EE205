#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Weapon.hpp"

using namespace std;

class Player {
protected:
		std::string name;
		//std::string rarity;
		//std::string type;
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
		Player(std::string name_, Weapon *weap_); //Overloaded Constructor
		//Player(const Player& other); //copy constructor
		//Player(Player&& other); //move constructor

		//Getters
		std::string get_name();
		//std::string get_rarity();
		//std::string get_type();
		int get_health();
		int get_MAXhealth();
		int get_mana();
		int get_MAXmana();
		int get_attack();
		int get_defense();

		//Setters
		void set_name(std::string s);
		//void set_rarity(std::string r);
		//void set_type(std::string t);
		void set_health(int hp);
		void set_MAXhealth(int hp);
		void set_mana(int mp);
		void set_MAXmana(int mp);
		void set_attack(int atk);
   	void set_defense(int d);
};
#endif //PLAYER_HPP
