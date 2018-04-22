#include <string>
#include <vector>
#include "game-utility.hpp"

//Generates enemy 
class Enemy {
	private:
		unsigned int enemy_health_point;
		unsigned int enemy_MAX_health_point;
		unsigned int enemy_def;
		unsigned int enemy_atk;
		std::string enemy_subtype;
		std::map <std::string,std::string> eff_enemy;
	
	public:
		//construct enemy
		Enemy(unsigned char tier_level);
		
		//getters
		unsigned int enemy_hp();
		
		unsigned int enemy_atk();
		
		unsigned int enemy_def();
		
		std::string enemy_subtype();
		
		std::map <std::string,std::string>  enemy_eff();
		
		//setter
		
		void damage_enemy(unsigned int damge);
		
		void debuff_atk(unsigned int debuff);
		
		void debuff_def(unsigned int debuff);
		
}
		
		