#include <string>
#include <utility>

#include "game-utility.hpp"
#include "Unit.hpp"
#include "Enemy.hpp"

Enemy::Enemy(unsigned int tier_level) {
	int enemy_subtype;
	tier = tier_level;
	if (tier_level == 1) {
		//Beasts
		enemy_subtype = RandNum(1, 4);
		if(enemy_subtype == 1) {
			name =  "Wolf";
			MAXhealth = health = 3;
			attack = 3;
			defense = 1;
			elemental_Type = "Normal";
			weapon_Type = "Normal";
		}
		else if (enemy_subtype == 2) {
			name =  "Cougar";
			MAXhealth = health = 3;
			attack = 4;
			defense = 0;
			elemental_Type = "Normal";
			weapon_Type = "Normal";
		}
		else {
			name =  "Bear";
			MAXhealth = health = 3;
			attack = 2;
			defense = 2;
			elemental_Type = "Normal";
			weapon_Type = "Normal";
		}
	}
	else if(tier_level == 2) {
		//Highway bandit
		enemy_subtype = RandNum(1, 4);
		if(enemy_subtype == 1) {
			name =  "Highway Bandit";
			MAXhealth = health = 8;
			attack = 4;
			defense = 2;
			elemental_Type = "Normal";
			weapon_Type = random_wep_eff(100);
		}
		else if (enemy_subtype == 2) {
			name =  "Rogue Knight";
			MAXhealth = health = 12;
			attack = 3;
			defense = 4;
			elemental_Type = "Normal";
			weapon_Type = random_wep_eff(100);
		}
		else {
			name =  "Rogue Mage";
			MAXhealth = health = 8;
			attack = 6;
			defense = 0;
			elemental_Type = random_element_eff(100);
			weapon_Type = "Normal";
		}
	}
	else if(tier_level == 3) {
		//Skeletons
		enemy_subtype = RandNum(1, 5);
		if(enemy_subtype == 1) {
			name =  "Skeleton warrior";
			MAXhealth = health = 20;
			attack = 5;
			defense = 4;
			elemental_Type = "Normal";
			weapon_Type = random_wep_eff(100);
		}
		else if (enemy_subtype == 2) {
			name =  "Skeleton Mage";
			MAXhealth = health = 12;
			attack = 10;
			defense = 0;
			elemental_Type = random_element_eff(100);
			weapon_Type = "Normal";
		}
		else if (enemy_subtype == 3) {
			name =  "Skeleton Archer";
			MAXhealth = health = 14;
			attack = 8;
			defense = 2;
			elemental_Type = "Normal";
			weapon_Type = "Bow";
		}
		else {
			name =  "Arch Lich";
			MAXhealth = health = 30;
			attack = 6;
			defense = 3;
			elemental_Type = random_element_eff(75);
			weapon_Type = "Normal";
		}
	}
	else if(tier_level == 4) {
		//Horrors enemys
		enemy_subtype = RandNum(1, 5);
		if(enemy_subtype == 1) {
			name =  "Deformed beast";
			MAXhealth = health = 20;
			attack = 12;
			defense = 0;
			elemental_Type = random_element_eff(20);
			weapon_Type = "Normal";
		}
		else if (enemy_subtype == 2) {
			name =  "Deformed human";
			MAXhealth = health = 30;
			attack = 6;
			defense = 6;
			elemental_Type = random_element_eff(20);
			weapon_Type = random_wep_eff(100);
		}
		else if (enemy_subtype == 3) {
			name =  "Other worldly horror";
			MAXhealth = health = 30;
			attack = 10;
			defense = 10;
			elemental_Type = random_element_eff(20);
			weapon_Type = random_wep_eff(50);
		}
		else {
			name =  "Horror gate guard";
			MAXhealth = health = 40;
			attack = 10;
			defense = 15;
			elemental_Type = random_element_eff(100);
			weapon_Type = random_wep_eff(100);
		}
	}
	else if (tier_level == 5) {
		//Demon
		enemy_subtype = RandNum(1, 4);
		if(enemy_subtype == 1) {
			name =  "Fire Demon";
			MAXhealth = health = 40;
			attack = 20;
			defense = 10;
			elemental_Type = "Fire";
			weapon_Type = "Normal";
		}
		else if (enemy_subtype == 2) {
			name =  "Nature Demon";
			MAXhealth = health = 50;
			attack = 15;
			defense = 15;
			elemental_Type = "Nature";
			weapon_Type = "Normal";
		}
		else {
			name =  "Water Demon";
			MAXhealth = health = 60;
			attack = 10;
			defense = 20;
			elemental_Type = "Water";
			weapon_Type = "Normal";
		}
	}
	else if(tier_level == 6) {
		name =  "Satan";
		MAXhealth = health = 100;
		attack = 20;
		defense = 20;
		elemental_Type = "Normal";
		weapon_Type = "Normal";
	}
	else {
		throw "Error: not a valid tier level" ;
	}

}

int Enemy::get_tier(void) {return this->tier;}
std::string Enemy::get_element(void) { return this->elemental_Type; }
std::string Enemy::get_wep_type(void) { return this->weapon_Type; }
