#include <iostream>
#include <string>
#include "Weapon.hpp"
#include <ctime>
#include <cstdlib>
#include "game-utility.hpp"
#include "Color.hpp"

using namespace std;

int main() {

	unsigned int randNum;
	char input = '0';
	Weapon testweapon;
	srand(time(0));

	cout << FRED("Welcome to Weapon testing") << endl;
	cout << "Enter q to quit" << endl;
	cout << "" << endl;
	cout << "" << endl;

	cout << "Create default weapon" << endl;
	cout << "Weapon type: " << testweapon.get_type() << endl;
	cout << "Rarity: "  << testweapon.get_rarity() << endl;
	cout << "ATK: "  << testweapon.get_wdamage() << endl;
	cout << "DEF: "  << testweapon.get_wdefense() << endl;
	cout << "MaxHP: "  << testweapon.get_MAXhealth() << endl;
	cout << "MaxMP: "  << testweapon.get_MAXmana() << endl;
	cout << "" << endl;

	while(input != 'q') {
		randNum = RandNum(1 , 6);

		Warrior_Weap testweapon1(randNum);

		cout << "Create Warrior weapon" << endl;
		cout << "Weapon type: " << testweapon1.get_type() << endl;
		cout << "Rarity: "  << testweapon1.get_rarity() << endl;
		cout << "ATK: "  <<  testweapon1.get_wdamage() << endl;
		cout << "DEF: "  << testweapon1.get_wdefense() << endl;
		cout << "MaxHP: "  <<  testweapon1.get_MAXhealth() << endl;
		cout << "MaxMP: "  << testweapon1.get_MAXmana() << endl;

		Mage_Weap testweapon2(randNum);
		cout << "" << endl;

		cout << "Create Mage weapon" << endl;
		cout << "Weapon type: " << testweapon2.get_type() << endl;
		cout << "Rarity: "  << testweapon2.get_rarity() << endl;
		cout << "ATK: "  <<  testweapon2.get_wdamage() << endl;
		cout << "DEF: "  << testweapon2.get_wdefense() << endl;
		cout << "MaxHP: "  <<  testweapon2.get_MAXhealth() << endl;
		cout << "MaxMP: "  << testweapon2.get_MAXmana() << endl;
		cout << "" << endl;

		cin >> input;

		cin.clear();
		fflush(stdin);
	}

return 0;
}
