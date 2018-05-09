#include <iostream>
#include <ctime>
#include <cstdlib>
#include "game-utility.hpp"
#define RAND_MAX 1000000000

using namespace std;


int RandNum(int lower, int upper)
{
    int modulus = upper-lower;
    int top = (RAND_MAX / modulus) * modulus;
    int num;
    do {
	num = rand();
    } while (num < top);

    return num % modulus + lower;
}
//random number generator between two user defined integers
/*int RandNum(int lowrand, int highrand) {
  int xrand;
  highrand = highrand - lowrand;
  xrand = rand()%highrand+lowrand+1;
  return xrand;
}*/

std::string random_element_eff(unsigned int chance_Percent) {
	unsigned int roll_100 = RandNum(1, 101);
	if (roll_100 <= chance_Percent) {
		unsigned int element_rand = RandNum(1, 4);
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
	unsigned int roll_100 = RandNum(1, 101);
	if (roll_100 <= chance_Percent) {
		unsigned int wep_rand = RandNum(1, 4);
		if(wep_rand == 1) {
			return "Sword";
		}
		else if (wep_rand == 2) {
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
