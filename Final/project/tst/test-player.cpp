#include <iostream>
#include <string>
#include <utility>
#include <ctime>
#include <cstdlib>
#include "player.hpp"
#include "game-utility.hpp"
#include "weapon.hpp"

using namespace std;

int main() {
Weapon basicwep;
Player testplayer("Jared", basicwep);
cout << "Name : " << testplayer.get_name() << endl;
cout << "MaxHP : " <<  testplayer.get_MAXhealth() << endl;
cout << "HP : " <<  testplayer.get_health() << endl;
cout << "ATK : " <<  testplayer.get_attack() << endl;
cout << "DEF : " <<  testplayer.get_defense() << endl;
cout << "Mana : " << testplayer.get_mana() << endl;
cout << "Max Mana : " << testplayer.get_MAXmana() << endl;


	}
