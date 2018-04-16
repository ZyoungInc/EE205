#include <string>
#include <vector>
#include "game-utility.hpp"

//Generates enemy 
class Enemy {
	private:
		unsigned int enemy_health_point;
		unsigned int enemy_def;
		unsigned int enemy_atk;
		
	
	public:
		//construct enemy
		Enemy(unsigned char tier_level);
		
		//getters
		unsigned int enemy_hp();
		
		unsigned int enemy_atk();
		
		unsigned int enemy_def();
		
		std::string enemy_type();
		
		//setter
		
		void damage_enemy(unsigned int damge);
		
}
		
		