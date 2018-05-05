#include <iostream>
#include <string>
#include <utility>
#include <ctime>
#include <cstdlib>
#include "Player.hpp"
#include "game-utility.hpp"
#include "Weapon.hpp"
#include "Color.hpp"

using namespace std;

int main() {
	unsigned int randomNum;
	//int flag = 0;
	char input = '0';
	srand(time(0));

	//cout << "This program continously generates enemy until 1 is pressed" << endl;
	cout << "Enter q to quit" << endl;
	cout << "" << endl;
	cout << "" << endl;

	while (input != 'q') {
		randomNum = RandNum(1, 6);
		Warrior_Weap weap(randomNum);

		cout << "Weapon type: " << weap.get_type() << endl;
		cout << "Rarity: "  << weap.get_rarity() << endl;
		cout << FRED("ATK: ")  <<  weap.get_wdamage() << endl;
		cout << FMAG("DEF: ")  << weap.get_wdefense() << endl;
		cout << FGRN("MaxHP: ")  <<  weap.get_MAXhealth() << endl;
		cout << FBLU("MaxMP: ")  << weap.get_MAXmana() << endl;
		cout << "" << endl;


		Player newPlayer("Nate", &weap);


		cout << UNDL("Name : ") << newPlayer.get_name() << endl;
		cout << FGRN("MaxHP : ") <<  newPlayer.get_MAXhealth() << endl;
		cout << FGRN("HP : ") <<  newPlayer.get_health() << endl;
		cout << FBLU("MaxMP : ") <<  newPlayer.get_MAXmana() << endl;
		cout << FBLU("MP : ") <<  newPlayer.get_mana() << endl;
		cout << FRED("ATK : ") <<  newPlayer.get_attack() << endl;
		cout << FMAG("DEF : ") <<  newPlayer.get_defense() << endl;
		cout << "RARITY : " << weap.get_rarity() << endl;
		cout << "weapon TYPE : " << weap.get_type() << endl;

		cin >> input;

		cin.clear();
		fflush(stdin);

	}
	return 0;
}
