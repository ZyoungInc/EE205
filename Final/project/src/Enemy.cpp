#include <string>
#include <vector>
#include "game-utility.hpp"

Enemy(unsigned char tier_level) {
	switch(tier_level) {
    case 1 : 
		unsigned char enemy_subtype = RandNum(1, 3);
    case 2 : 
		unsigned char enemy_subtype = RandNum(1, 3);
	case 3 : 
		unsigned char enemy_subtype = RandNum(1, 3);
	case 4 : 
		//boss
	default:
		throw "Error: not a valid tier level" ;
		
	}
	
}