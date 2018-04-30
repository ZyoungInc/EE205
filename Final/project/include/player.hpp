#include <iostream>
#include <string>
#include <vector>
#include "Weapon.hpp"
using namespace std;

class Player{
	private:
		string name;
		int health;
		int MAXhealth;
		int mana;
		int MAXmana;
		int att;
		int def;
		pair <string, string> player_eff;
		Weapon currwep ;

	public:
		Player();
		Player(string name, Weapon wep);
		Player(Player&& other, char rarity_level);
		pair <string, string>  get_player_eff(void);

		//Getters
		string get_name();
		int get_health();
		int get_MAXhealth();
		int get_mana();
		int get_MAXmana();
		int get_attack();
		int get_defense();

		//Setters
		void set_name(std::string s);
		void set_health(int hp);
		void set_MAXhealth(int hp);
		void set_mana(int mp);
		void set_MAXmana(int mp);
		void set_attack(int atk);
		void set_defense(int d);
};
