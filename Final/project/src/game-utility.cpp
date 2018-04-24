#include <iostream>
#include <ctime>
#include <cstdlib>
#include "game-utility.hpp"
using namespace std;

//random number generator between two user defined integers
int RandNum(int lowrand, int highrand) {
  int xrand;

  highrand = highrand - lowrand;

  //srand(time(0)); not required here but needed in beginning of main
  xrand = rand()%highrand+lowrand+1;
  return xrand;
}


std::string random_element-eff(unsigned int chance_Percent) {
	unsigned int roll_100 = RandNum( 1 , 100);
	if (roll_100 <= chance_Percent) {
		unsigned int element_rand = RandNum(1, 3);
		if(element_rand == 1) {
			return "Fire"; 
		}
		else if (element_rand == 2) {
			return "Nature"; 
		}
		else {
			return "Water";
		}
	}
	else {
		return "Normal";
	}
}
		
std::string random_wep_eff(unsigned int chance_Percent){
	unsigned int roll_100 = RandNum( 1 , 100);
	if (roll_100 <= chance_Percent) {
		unsigned int wep_rand = RandNum(1, 3);
		if(element_rand == 1) {
			return "Sword"; 
		}
		else if (element_rand == 2) {
			return "Lance"; 
		}
		else {
			return "Axe";
		}
	}
	else {
		return "Normal";
	}
}
	