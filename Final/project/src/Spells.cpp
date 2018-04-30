#include <iostream>
#include <string>
#include <vector>
#include "Spells.hpp"
#define HEAL_DMG 2
#define VAMPIRE_DMG 2

Spell::Spell() :
	cost(0),
    damage(0),
    hits(0),
    name(""),
    EleType("") {
	}


//Overloaded constructor for spells
Spell::Spell(int c, int d, int h, string n, string e ) :
    cost(c),
    damage(d),
    hits(h),
    name(n),
    EleType(e) {
	}

//Getters
int Spell::get_cost() {return cost;}
int Spell::get_damage() {return damage;}
int Spell::get_hits()  {return hits;}
string Spell::get_name()  {return name;}
string Spell::get_EleType() {return EleType;}
int Spell::check_Effect(int playerATK) {
	if (this->name == "Heal") {
		return  (playerATK * HEAL_DMG);
	}
	if (this->name == "VampiricStrike") {
		return (playerATK * VAMPIRE_DMG);
	}
	else {
		return 0;
	}
}

//Setters
void Spell::set_cost(int c) {cost = c;}
void Spell::set_damage(int d){ damage = d;}
void Spell::set_hits(int h){hits = h;}
void Spell::set_name(string n){name = n;}
void Spell::set_Type(string e){EleType = e;}

string magearray[4] = {"Fireball: Fire Element, Damage: 1.5x ATK, Cost: 10 Mana", "Torrent: Water Element, Damage: 1.5x ATK, Cost: 10 Mana", "Wrath: Nature Element, Deals 1.5x ATK", "Restore: Heals you for 1/2 MaxHP. Cost: 20 Mana" };

string warriorarray[4] = {"Slash: No Element, Damage: 2x ATK, Cost 10 Mana", "Flurry: No Element, Damage: 1x ATK 3 times, Cost: 10 Mana", "HeavyBlow: No Element, Deals 5x ATK, Cost: 10 Mana", "VampiricStrike:No Element Damage: 2x ATK Heals for Damage Dealt, Cost: 20 Mana " };

vector<Spell> MakeSpellBook(int choice) {
	vector<Spell> tempSpellBook;
	if (choice == 1)
    {
		Spell FireBall(1, 2, 1, "Fireball", "Fire") ;
		Spell Torrent(1, 2, 1, "Torrent", "Water");
		Spell Wrath(1, 2, 1, "Wrath", "Nature");
		Spell Heal(1, 2, 1, "Heal", "None");
		tempSpellBook.push_back(FireBall);
		tempSpellBook.push_back(Torrent);
		tempSpellBook.push_back(Wrath);
		tempSpellBook.push_back(Heal);
		return tempSpellBook;
    }
    else if (choice == 2) {
		Spell Slash(1, 3, 1, "Slash", "None");
		Spell Flurry(1, 1, 3, "Flurry", "None");
		Spell HeavyBlow(1, 5, 1, "HeavyBlow", "None");
		Spell VampiricStrike (1, 2, 1, "VampiricStrike", "None");
		tempSpellBook.push_back(Slash);
		tempSpellBook.push_back(Flurry);
		tempSpellBook.push_back(HeavyBlow);
		tempSpellBook.push_back(VampiricStrike);
		return tempSpellBook;
    }
	else {
		throw "Invalid choice";
	}
}
