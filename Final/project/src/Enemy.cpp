#include <string>
#include <utility>
#include "game-utility.hpp"
#include "unit.hpp"
#include "Enemy.hpp"

Enemy::Enemy(unsigned char tier_level) {
	switch(tier_level) {
    case 1 : 
		//Beasts
		unsigned char enemy_subtype = RandNum(1, 3);
		if(enemy_subtype == 1) {
			Unit("Wolf", 5, 0, 2 , 0);
			eff_enemy.first = "Normal";
			eff_enemy.second = "Normal";
		}
		else if (enemy_subtype == 2) {
			Unit("Cougar", 3, 0 , 4 , 0);
			eff_enemy.first = "Normal";
			eff_enemy.second = "Normal";
		}
		else {
			Unit("Bear", 3, 0 , 4 , 0);
			eff_enemy.first = "Normal";
			eff_enemy.second = "Normal";
		}
		break;
    case 2 : 
		//Highway bandit
		unsigned char enemy_subtype = RandNum(1, 3);
		if(enemy_subtype == 1) {
			Unit("Highway Bandit", 8, 0 , 4 , 2);
			eff_enemy.first = "Normal";
			eff_enemy.second = "Normal";
		}
		else if (enemy_subtype == 2) {
			Unit("Rogue Knight", 10, 0 , 4 , 4);
			eff_enemy.first = random_element-eff(100);
			eff_enemy.second = "Normal";
			
		}
		else {
			Unit("Rogue Mage", 8, 0 , 6 , 0);
			eff_enemy.first = "Normal"
			eff_enemy.second = random_wep_eff(100);
		break;
	case 3 : 
		//Skeletons
		unsigned char enemy_subtype = RandNum(1, 4);
		if(enemy_subtype == 1) {
			Unit("Skeleton warrior", 14, 0 , 6 , 2);
			eff_enemy.first = "Normal";
			eff_enemy.second = "Normal";
		}
		else if (enemy_subtype == 2) {
			Unit("Skeleton Mage", 12, 0 , 8 , 0);
			eff_enemy.first = random_element-eff(100);
			eff_enemy.second = "Normal";
		}
		else if (enemy_subtype == 3) {
			Unit("Skeleton Archer", 12, 0 , 8 , 0);
			eff_enemy.first = "Normal";
			eff_enemy.second = "Normal";
		else {
			Unit("Arch Lich", 18, 0 , 8 , 8);
			eff_enemy.first = random_element-eff(100);
			eff_enemy.second = "Normal";
		}
		break;
	case 4 : 
		//Horrors enemys
		unsigned char enemy_subtype = RandNum(1, 4);
		if(enemy_subtype == 1) {
			Unit("Deformed beast", 16, 0 , 6 , 0);
			eff_enemy.first = random_element-eff(20);
			eff_enemy.second = "Normal";
		}
		else if (enemy_subtype == 2) {
			Unit("Deformed human", 18, 0 , 6 , 6);
			eff_enemy.first = random_element-eff(20);
			eff_enemy.second = random_wep_eff(100);
		}
		else if (enemy_subtype == 3) {
			Unit("Other worldly horror", 20, 0 , 10, 10);
			eff_enemy.first = random_element-eff(20);
			eff_enemy.second = random_wep_eff(50);
		else {
			Unit("Horror gate guard", 40, 0 , 10, 15);
			eff_enemy.first = random_element-eff(100);
			eff_enemy.second = random_wep_eff(100);
		}
		break;
	case 5 :
		//Demon
		if(enemy_subtype == 1) {
			Unit("Fire Demon", 40, 0 , 20 , 10);
			eff_enemy.first = "Fire";
			eff_enemy.second = "Normal";
		}
		else if (enemy_subtype == 2) {
			Unit("Fire Demon", 50, 0 , 15 , 15);
			eff_enemy.first = "Nature";
			eff_enemy.second = "Normal";
		}
		else {
			Unit("Water Demon", 60, 0 , 10, 20);
			eff_enemy.first = "Water";
			eff_enemy.second = "Normal";
		
		}
		break;
	case 6 :
		Unit("Satan", 100, 0 , 20, 20);
		eff_enemy.first = "Normal";
		eff_enemy.second = "Normal";
		break;
	default:
		throw "Error: not a valid tier level" ;
		
	}
	
}

std::pair <std::string,std::string>  Enemy::get_enemy_eff() {
	std::pair <std::string, std::string> temp_enemy_eff;
	temp_enemy_eff.first = eff_enemy.first;
	temp_enemy_eff.second = eff_enemy.second;
	return temp_enemy_eff;
}