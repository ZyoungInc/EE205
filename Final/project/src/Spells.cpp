#include <iostream>
#include <string>
#include <vector>
#include "Spells.hpp"
#define HEAL_DMG 5
#define VAMPIRE_DMG 4

Spell::Spell() :
	cost(0),
    damage(0),
    hits(0),
    name(""),
    spellDesc("") {
	}


//Overloaded constructor for spells
Spell::Spell(int c, int d, int h, string n, string desc ) :
    cost(c),
    damage(d),
    hits(h),
    name(n),
    spellDesc(desc) {
	}

//Getters
int Spell::get_cost() {return cost;}
int Spell::get_damage() {return damage;}
int Spell::get_hits()  {return hits;}
string Spell::get_name()  {return name;}
string Spell::get_spellDesc() {return spellDesc;}
int Spell::check_Effect(int playerATK) {
	if (this->name == "Heal") {
		return  (playerATK * HEAL_DMG);
	}
	else if (this->name == "VampiricStrike") {
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
void Spell::set_spellDesc(string desc){spellDesc = desc;}

vector<Spell> MakeSpellBook(int choice, std::string weapon, std::string element) {
	vector<Spell> tempSpellBook;
	if (choice == 2)
    {
			//Spell(cost, damage, hits, name, spell description)
			if(element == "Fire"){
				Spell FireBall(10, 3, 1, "Fireball", "Fireball: deal 3x ATK, costs 10 mana") ;
				Spell Scorch(15, 5, 1, "Scorch", "Scorch: deal 5x ATK, costs 15 mana");
				Spell FireBlast(50, 10, 1, "FireBlast", "FireBlast: deal 10x ATK, costs 50 mana");
				Spell Heal(20, 0, 1, "Heal", "Restore: heals you for 5x ATK");
				tempSpellBook.push_back(FireBall);
				tempSpellBook.push_back(Scorch);
				tempSpellBook.push_back(FireBlast);
				tempSpellBook.push_back(Heal);
				return tempSpellBook;
			}
			else if(element == "Water"){
				Spell Tsunami(10, 3, 1, "Tsunami", "Tsunami: deal 3x ATK, costs 10 mana") ;
				Spell Vortex(25, 5, 3, "Vortex", "Vortex: deal 5x ATK 3x times, costs 25 mana");
				Spell Riptide(40, 6, 2, "Riptide", "Riptide: deal 6x ATK 2x times, costs 40 mana");
				Spell Heal(20, 0, 1, "Heal", "Restore: heals you for 5x ATK");
				tempSpellBook.push_back(Tsunami);
				tempSpellBook.push_back(Vortex);
				tempSpellBook.push_back(Riptide);
				tempSpellBook.push_back(Heal);
				return tempSpellBook;
			}
			else if(element == "Nature"){
				Spell Gust(10, 3, 1, "Gust", "Gust: deal 3x ATK, costs 10 mana") ;
				Spell ThunderStorm(30, 5, 5, "Thunder Storm", "Thunder Storm: deal 5x ATK 5x times, costs 30 mana");
				Spell Tornado(50, 5, 10, "Tornado", "Tornado: deal 5x ATK 10x times, costs 50 mana");
				Spell Heal(20, 0, 1, "Heal", "Restore: heals you for 5x ATK");
				tempSpellBook.push_back(Gust);
				tempSpellBook.push_back(ThunderStorm);
				tempSpellBook.push_back(Tornado);
				tempSpellBook.push_back(Heal);
				return tempSpellBook;
			}
			else{//Default no weapon
				Spell FlameSpew(5, 3, 1, "FlameSpew", "FlameSpew: deal 3x ATK, costs 5 mana") ;
				Spell WaterGun(5, 3, 1, "Water Gun", "Water Gun: deal 3x ATK, costs 5 mana");
				Spell WhirlWind(5, 3, 1, "WhirlWind", "WhirlWind: deal 3x ATK, costs 5 mana");
				Spell Heal(10, 0, 1, "Heal", "Restore: heals you for 5x ATK, costs 10 mana");
				tempSpellBook.push_back(FlameSpew);
				tempSpellBook.push_back(WaterGun);
				tempSpellBook.push_back(WhirlWind);
				tempSpellBook.push_back(Heal);
				return tempSpellBook;
			}
    }
    else if (choice == 1) {
			if(weapon == "Sword"){
				//Spell(cost, damage, hits, name, spell description)
				Spell Slash(5, 3, 1, "Slash", "Slash: deal 3x ATK, costs 5 Rage");
				Spell SliceDice(15, 3, 3, "Slice and Dice", "Slice and Dice: deal 3x ATK 3x 3x times, costs 15 Rage");
				Spell Astra(30, 5, 5, "Astra", "Astra: deal 5x ATK 5x times, costs 20 Rage");
				Spell VampiricStrike (20, 5, 1, "VampiricStrike", "VampiricStrike: deal 5x ATK and heal, costs 30 Rage");
				tempSpellBook.push_back(Slash);
				tempSpellBook.push_back(SliceDice);
				tempSpellBook.push_back(Astra);
				tempSpellBook.push_back(VampiricStrike);
				return tempSpellBook;
			}
			else if(weapon == "Axe"){
				//Spell(cost, damage, hits, name, spell description)
				Spell ReckfulSwing(10, 5, 1, "ReckfulSwing", "ReckfulSwing: deal 5x ATK, costs 10 Rage");
				Spell Guillotine(20, 6, 1, "Guillotine", "Guillotine: deal 6x ATK, costs 20 Rage");
				Spell HeavyBlow(40, 12, 1, "HeavyBlow", "HeavyBlow: deal 12x ATK, costs 40 Rage");
				Spell VampiricStrike (20, 4, 1, "VampiricStrike", "VampiricStrike: deal 4x ATK and heal, costs 20 Rage");
				tempSpellBook.push_back(ReckfulSwing);
				tempSpellBook.push_back(Guillotine);
				tempSpellBook.push_back(HeavyBlow);
				tempSpellBook.push_back(VampiricStrike);
				return tempSpellBook;
			}
			else if(weapon == "Lance"){
				//Spell(cost, damage, hits, name, spell description)
				Spell Sweep(5, 3, 1, "Sweep", "Sweep: deal 3x ATK, costs 5 Rage");
				Spell Flurry(15, 3, 5, "Flurry", "Flurry; deal 3x ATK 5x times, costs 15 Rage");
				Spell Impale(40, 10, 1, "Impale", "Impale: deal 10x ATK, costs 40 Rage");
				Spell VampiricStrike (20, 4, 1, "VampiricStrike", "VampiricStrike: deal 4x ATK and heal, costs 20 Rage");
				tempSpellBook.push_back(Sweep);
				tempSpellBook.push_back(Flurry);
				tempSpellBook.push_back(Impale);
				tempSpellBook.push_back(VampiricStrike);
				return tempSpellBook;
			}
			else{//Default no weapon
				//Spell(cost, damage, hits, name, spell description)
				Spell SuckerPunch(5, 3, 1, "SuckerPunch", "SuckerPunch: deal 3x ATK, costs 5 Rage");
				Spell Pummel(10, 3, 3, "Pummel", "Pummel: deal 3x ATK, costs 10 Rage");
				Spell RagingBlow(20, 5, 1, "RagingBlow", "RagingBlow: deal 5x ATK, costs 20 Rage");
				Spell VampiricStrike (20, 4, 1, "VampiricStrike", "VampiricStrike: deal 4x ATK and heal, costs 20 Rage");
				tempSpellBook.push_back(SuckerPunch);
				tempSpellBook.push_back(Pummel);
				tempSpellBook.push_back(RagingBlow);
				tempSpellBook.push_back(VampiricStrike);
				return tempSpellBook;
			}
    }
	else {
		throw "Invalid choice";
	}
}
