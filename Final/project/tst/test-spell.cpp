#include <iostream>
#include "spells.hpp"
#include <vector>

using namespace std;

int main() {
	vector<Spell> testMageSpell(MakeSpellBook(1));
	vector<Spell> testWarSpell(MakeSpellBook(2));
	
	for(unsigned int i = 0 ; i <testMageSpell.size();i++) {
		cout << testMageSpell[i].get_name() << endl;
	}
	
	for(unsigned int i = 0 ; i <testMageSpell.size();i++) {
		cout << testMageSpell[i].get_cost() << endl;
	}
	
	cout << "Healing done by Fireball : " << testMageSpell[2].check_Effect(49) << endl;
	cout << "Healing done by VampiricStrike : " << testWarSpell[3].check_Effect(3) << endl;
	
	return 0;	
}