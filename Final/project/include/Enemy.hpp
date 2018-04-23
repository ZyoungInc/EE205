#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include <utility>
#include "game-utility.hpp"
#include "unit.hpp"

//Generates enemy 
class Enemy public unit{
	private:
		std::pair <std::string,std::string> eff_enemy;
	
	public:
		//construct enemy base on tier level, BOSS is tier 6 (satan)
		Enemy(unsigned char tier_level);
	
		/*Function description : Grab the enemy's effects, first is elemental
		  second is weapon type
		  Input: None
		  Output: string pair of enemy effect*/
		std::pair <std::string,std::string>  get_enemy_eff(void);
}