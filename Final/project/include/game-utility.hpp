#ifndef GAME_UTILITY_HPP
#define GAME_UTILITY_HPP

#include <string>
#include <vector>


//random number generator between two user defined integers
int RandNum(int lowrand, int highrand);

/*Function description : Generates a random element based on chance else normal element
/ Input: unsigned int example 40% = 40
  Output: string of the element example "Fire" */
std::string random_element_eff(unsigned int chance_Percent);

/*Function description : Generates a random weapon based on chance else normal wep
/ Input: unsigned int example 40% = 40
  Output: string of the element example "Fire" */		
std::string random_wep_eff(unsigned int chance_Percent);		

#endif // GAME_UTILITY_HPP

