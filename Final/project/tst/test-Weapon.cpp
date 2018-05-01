#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "Weapon.hpp"
#include "game-utility.hpp"
#include "Color.hpp"

using namespace std;

int main() {

	unsigned int randNum;
	char input = '0';
	Weapon testweapon;
	srand(time(0));

	cout << FCYN("Welcome to Weapon testing") << endl;
	cout << "" << endl;

	cout << UNDL("Create default weapon") << endl;
	cout << "Weapon type: " << testweapon.get_type() << endl;
	cout << "Rarity: " << testweapon.get_rarity() << endl;
	cout << FRED("ATK: ") << testweapon.get_wdamage() << endl;
	cout << FMAG("DEF: ") << testweapon.get_wdefense() << endl;
	cout << FGRN("MaxHP: ") << testweapon.get_MAXhealth() << endl;
	cout << FBLU("MaxMP: ") << testweapon.get_MAXmana() << endl;
	cout << "" << endl;

//Loop for generating more weapons
	while(input != 'q') {
		randNum = RandNum(1 , 6);

		Warrior_Weap testweapon1(randNum);

		cout << UNDL("Create Warrior weapon") << endl;
		cout << "Weapon type: " << testweapon1.get_type() << endl;
		cout << "Rarity: "  << testweapon1.get_rarity() << endl;
		cout << FRED("ATK: ")  <<  testweapon1.get_wdamage() << endl;
		cout << FMAG("DEF: ")  << testweapon1.get_wdefense() << endl;
		cout << FGRN("MaxHP: ")  <<  testweapon1.get_MAXhealth() << endl;
		cout << FBLU("MaxMP: ")  << testweapon1.get_MAXmana() << endl;

		Mage_Weap testweapon2(randNum);
		cout << "" << endl;

		cout << UNDL("Create Mage weapon") << endl;
		cout << "Weapon type: " << testweapon2.get_type() << endl;
		cout << "Rarity: "  << testweapon2.get_rarity() << endl;
		cout << FRED("ATK: ")  <<  testweapon2.get_wdamage() << endl;
		cout << FMAG("DEF: ")  << testweapon2.get_wdefense() << endl;
		cout << FGRN("MaxHP: ")  <<  testweapon2.get_MAXhealth() << endl;
		cout << FBLU("MaxMP: ")  << testweapon2.get_MAXmana() << endl;
		cout << "" << endl;

		cout << "Currently in wepon testing:" << endl;
		cout << "Enter any number to generate a new set" << endl;
		cout << FYEL("Or enter 'q' to quit") << endl;
		cout << "" << endl;

		cin >> input;

		cin.clear();
		fflush(stdin);
	}

return 0;
}
