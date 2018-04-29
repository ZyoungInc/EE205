#include <iostream>
#include <string>
#include <vector>
#include "spells.hpp"
using namespace std;
  Spell::Spell (int c, int d, int h, string n, string e ):
    cost(c),
    damage(d),
    hits(h),
    name(n),
    EleType(e)
  {}
  //Choice between 2 sets of spells
  Spell::Spellset(int Choice){
    if (Choice == 1)
    {
    Fireball Spell(1, 2, 1, "Fireball", "Fire")
    Torrent Spell (1, 2, 1, "Torrent", "Water")
    Wrath Spell (1, 2, 1, "Wrath", "Nature")
    Heal Spell (1, 2, 1, "Heal", "None")
    }
    else if(Choice == 2) {
      Slash Spell (1, 3, 1, "Slash", "None")
      Flurry Spell (1, 1, 3, "Flurry", "None")
      HeavyBlow Spell (1, 5, 1, "HeavyBlow", "None")
      VampiricStrike Spell (1, 2, 1, "VampiricStrike", "None")
    }

}

//Getters
int Spell::get_cost() const {return cost;}
int Spell::get_damage() const{return damage;}
int Spell::get_hits() const {return hits;}
string Spell::get_name() const {return name;}
string Spell::get_EleType() const {return EleType;}

//Setters
void Spell::set_cost(int c) {cost = c;}
void Spell::set_damage(int d){ damage = d;}
void Spell::set_hits(int h){hits = h;}
void Spell::set_name(string n){name = n;}
void Spell::set_Type(string e){EleType = e;}

void Spell::Effect(){
if (Spell.name == "Heal") player.health = player.health + (player.ATK()*Heal.damage)
if (Spell.name == "VampiricStrike") player.health = player.health +(player.ATK()*VampiricStrike.damage)
}
string magearray[4] = {"Fireball: Fire Element, Damage: 1.5x ATK, Cost: 10 Mana", "Torrent: Water Element, Damage: 1.5x ATK, Cost: 10 Mana", "Wrath: Nature Element, Deals 1.5x ATK", "Restore: Heals you for 1/2 MaxHP. Cost: 20 Mana" };

string warriorarray[4] = {"Slash: No Element, Damage: 2x ATK, Cost 10 Mana", "Flurry: No Element, Damage: 1x ATK 3 times, Cost: 10 Mana", "HeavyBlow: No Element, Deals 5x ATK, Cost: 10 Mana", "VampiricStrike:No Element Damage: 2x ATK Heals for Damage Dealt, Cost: 20 Mana "
}
