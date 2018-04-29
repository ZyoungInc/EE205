#include <iostream>
#include <string>
#include <utility>
#include <ctime>
#include <cstdlib>
#include "Enemy.hpp"
#include "game-utility.hpp"

using namespace std;

int main() {
	unsigned int randomNum = 1;
	int flag = 0;
	srand(time(0));
	
	cout << "This program continously generates enemy until 1 is pressed" << endl;
	
	while (flag != 1) {
		randomNum = RandNum(1 , 6);
		Enemy newEnemy(randomNum);

		
		cout << "Randnum : " << randomNum << endl;
		cout << "Name : " << newEnemy.get_name() << endl;
		cout << "MaxHP : " <<  newEnemy.get_MAXhealth() << endl;
		cout << "HP : " <<  newEnemy.get_health() << endl;
		cout << "ATK : " <<  newEnemy.get_attack() << endl;
		cout << "DEF : " <<  newEnemy.get_defense() << endl;
		cout << "ELEMENTTYPE : " << newEnemy.get_element() << endl;
		cout << "weapon TYPE : " << newEnemy.get_wep_type() << endl;
		
		cin >> flag;
		
		cin.clear();
		fflush(stdin);

	}
}