#ifndef ENEMY_HPP
#define ENEMY_HPP

#include <string>
#include <utility>
#include "game-utility.hpp"
#include "Unit.hpp"


class Enemy : public Unit{

	private:
		std::string elemental_Type;
		std::string weapon_Type;
		int tier;

	public:
		//construct enemy base on tier level, BOSS is tier 6 (satan)
		Enemy(unsigned int tier_level);

		/*Function description : Grab the enemy's effects, first is elemental
		  second is weapon type
		  Input: None
		  Output: string pair of enemy effect*/
		std::string get_element(void);
		std::string get_wep_type(void);
		int get_tier(void);
};

#endif // ENEMY_HPP
