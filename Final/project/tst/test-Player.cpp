#include <iostream>
#include <string>
#include <utility>
#include <ctime>
#include <cstdlib>
#include "Player.hpp"
#include "game-utility.hpp"
#include "Weapon.hpp"

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
		Player newPlayer("Nate", &weap);


		cout << "Name : " << newPlayer.get_name() << endl;
		cout << "MaxHP : " <<  newPlayer.get_MAXhealth() << endl;
		cout << "HP : " <<  newPlayer.get_health() << endl;
		cout << "MaxMP : " <<  newPlayer.get_MAXmana() << endl;
		cout << "MP : " <<  newPlayer.get_mana() << endl;
		cout << "ATK : " <<  newPlayer.get_attack() << endl;
		cout << "DEF : " <<  newPlayer.get_defense() << endl;
		cout << "RARITY : " << weap.get_rarity() << endl;
		cout << "weapon TYPE : " << weap.get_type() << endl;

		cin >> input;

		cin.clear();
		fflush(stdin);

	}
	return 0;
}
