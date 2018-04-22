#include <string>
#include <vector>
#include "game-utility.hpp"

Enemy(unsigned char tier_level) {
	switch(tier_level) {
    case 1 : 
		//Beasts
		unsigned char enemy_subtype = RandNum(1, 3);
		if(enemy_subtype == 1) {
			enemy_MAX_health_point = 5;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 2;
			enemy_def = 0;
			enemy_subtype = "Wolf";
			eff_enemy.first = "Normal";
			eff_enemy.second = "Normal";
		}
		else if (enemy_subtype == 2) {
			enemy_MAX_health_point = 3;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 4;
			enemy_def = 0;
			enemy_subtype = "Cougar";
			eff_enemy.first = "Normal";
			eff_enemy.second = "Normal";
		}
		else {
			enemy_MAX_health_point = 5;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 2;
			enemy_def = 2;
			enemy_subtype = "Bear";
			eff_enemy.first = "Normal";
			eff_enemy.second = "Normal";
		}
		break;
    case 2 : 
		//Highway bandit
		unsigned char enemy_subtype = RandNum(1, 3);
		if(enemy_subtype == 1) {
			enemy_MAX_health_point = 8;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 4;
			enemy_def = 2;
			enemy_subtype = "Highway Bandit";
			eff_enemy.first = "Normal";
			eff_enemy.second = "Normal";
		}
		else if (enemy_subtype == 2) {
			enemy_MAX_health_point = 10;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 4;
			enemy_def = 4;
			enemy_subtype = "Rogue Knight";
			eff_enemy.first = "Normal";
			
			unsigned char enemy_subtype2 = RandNum(0, 3);
			if(enemy_subtype2 == 0) {
				eff_enemy.second = "Normal";
			}
			else if(enemy_subtype2 == 1) { 
					eff_enemy.second = "Sword";
			}
			else if(enemy_subtype2 == 2) { 
					eff_enemy.second = "Axe"; 
			}
			else {
					eff_enemy.second = "Lance"; 
			}
		}
		else {
			enemy_MAX_health_point = 8;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 6;
			enemy_def = 0;
			enemy_subtype = "Rogue Mage";
			
			unsigned char enemy_subtype1 = RandNum(1, 3);
			if(enemy_subtype1 == 1) {
				eff_enemy.first = "Fire"; 
			}
			else if (enemy_subtype1 == 2) {
				eff_enemy.first = "Nature"; 
			}
			else {
				eff_enemy.first = "Water";
			}
			eff_enemy.second = "Normal";
		}
		break;
	case 3 : 
		//Bandits
		unsigned char enemy_subtype = RandNum(1, 4);
		if(enemy_subtype == 1) {
			enemy_MAX_health_point = 14;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 6;
			enemy_def = 2;
			enemy_subtype = "Skeleton warrior";
			eff_enemy.first = "Normal";
			unsigned char enemy_subtype2 = RandNum(0, 3);
			if(enemy_subtype2 == 0) {
				eff_enemy.second = "Normal"; 
			}
			else if(enemy_subtype2 == 1) { 
					eff_enemy.second = "Sword";
			}
			else if(enemy_subtype2 == 2) { 
					eff_enemy.second = "Axe";
			}
			else {
					eff_enemy.second = "Lance"; 
			}
		}
		else if (enemy_subtype == 2) {
			enemy_MAX_health_point = 12;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 8;
			enemy_def = 0;
			enemy_subtype = "Skeleton Archer";
			eff_enemy.first = "Normal";
			eff_enemy.second = "Normal";
		}
		else if (enemy_subtype == 3) {
			enemy_MAX_health_point = 12;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 8;
			enemy_def = 0;
			enemy_subtype = "Skeleton Archer";
			eff_enemy.second = "Normal";
			
			if(enemy_subtype1 == 1) {
				eff_enemy.first = "Fire"; }
			else if (enemy_subtype1 == 2) {
				eff_enemy.first = "Nature"; }
			else {
				eff_enemy.first = "Water"; }		}
		else {
			enemy_MAX_health_point = 18;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 8;
			enemy_def = 8;
			enemy_subtype = " lich";
			unsigned char enemy_subtype1 = RandNum(1, 3);
			if(enemy_subtype1 == 1) {
				eff_enemy.first = "Fire"; }
			else if (enemy_subtype1 == 2) {
				eff_enemy.first = "Nature"; }
			else {
				eff_enemy.first = "Water"; }
			
			eff_enemy.second = "Normal"; 
			
		}
		break;
	case 4 : 
		//Horrors enemys
		unsigned char enemy_subtype = RandNum(1, 4);
		if(enemy_subtype == 1) {
			enemy_MAX_health_point = 16;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 6;
			enemy_def = 0;
			enemy_subtype = "Deformed beast";
			eff_enemy.first = "Normal";
			eff_enemy.second = "Normal";
		}
		else if (enemy_subtype == 2) {
			enemy_MAX_health_point = 18;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 6;
			enemy_def = 6;
			enemy_subtype = "Deformed Human";
			eff_enemy.first = "Normal";
			unsigned char enemy_subtype2 = RandNum(0, 3);
			if(enemy_subtype2 == 0) {
				eff_enemy.second = "Normal"; }
			else if(enemy_subtype2 == 1) { 
					eff_enemy.second = "Sword"; }
			else if(enemy_subtype2 == 2) { 
					eff_enemy.second = "Axe"; }
			else {
					eff_enemy.second = "Lance"; }
		}
		else if (enemy_subtype == 3) {
			enemy_MAX_health_point = 12;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 8;
			enemy_def = 0;
			enemy_subtype = "Other worldly horrors";
			eff_enemy.second = "Normal";
			
			if(enemy_subtype1 == 1) {
				eff_enemy.first = "Fire"; }
			else if (enemy_subtype1 == 2) {
				eff_enemy.first = "Nature"; }
			else {
				eff_enemy.first = "Water"; }		}
		else {
			enemy_MAX_health_point = 18;
			enemy_health_point = enemy_MAX_health_point;
			enemy_atk = 8;
			enemy_def = 8;
			enemy_subtype = " lich";
			unsigned char enemy_subtype1 = RandNum(1, 3);
			if(enemy_subtype1 == 1) {
				eff_enemy.first = "Fire"; }
			else if (enemy_subtype1 == 2) {
				eff_enemy.first = "Nature"; }
			else {
				eff_enemy.first = "Water"; }
			
			eff_enemy.second = "Normal"; 
			
		}
		break;
	case 5 :
	case 6 :
		enemy_MAX_health_point = 100;
		enemy_health_point = enemy_MAX_health_point;
		enemy_atk = 20;
		enemy_def = 20;
		enemy_subtype = "Satan(final boss)";
		eff_enemy.first = "Normal";
		eff_enemy.second = "Normal";
		}
	default:
		throw "Error: not a valid tier level" ;
		
	}
	
}

unsigned int enemy_hp(void) {
	return enemy_health_point;
}
		
unsigned int enemy_atk(void) {
	return enemy_atk;
}
		
unsigned int enemy_def(void) {
	return enemy_def;
}

std::string enemy_subtype(void) {
	return enemy_subtype;
}		
		
std::pair <std::string,std::string>  enemy_eff(void) {
	std::pair <std::string,std::string> temp_pair;
	temp_pair.first() = eff_enemy.first();
	temp_pair.second() = eff_enemy.second();
	return temp_pair;
}
//setter
		
unsigned int damage_enemy(unsigned int damage) {
	if (damage >= enemy_health_point) {
		enemy_health_point = 0;
	}
	else {
		enemy_health_point = enemy_health_point - damage;
	}
	return enemy_health_point;
}

void debuff_atk(unsigned int debuff, unsigned int turns){
}
		
void debuff_def(unsigned int debuff, unsigned int turns){
}