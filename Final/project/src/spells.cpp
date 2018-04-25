#include <iostream>
#include <string>
#include <vector>
#include "spells.hpp"
using namespace std;
  Spell::Spell (int c, int d, int cd, string n, string e ):
    cost(c),
    damage(d),
    cooldown(cd),
    name(n),
    EleType(e)
  {}
  //Choice between 2 sets of spells
  Spell::Spellset(int Choice){
    if (Choice == 1)
    {
    Fireball Spell(1, 5, 1, "Fireball", "Fire")
    Torrent Spell (1, 5, 1, "Torrent", "Water")
    Wrath Spell (1, 5, 1, "Wrath", "Nature")
    Heal Spell (1, 5, 2, "Heal", "None")
    }
    else if(Choice == 2) {
      Slash Spell (1, 5, 1, "Slash", "None")
      Flurry Spell (1, 5, 1, "Flurry", "None")
      HeavyBlow Spell (1, 5, 1, "HeavyBlow", "None")
      VampiricStrike Spell (1, 5, 1, "VampiricStrike", "None")
    }

}

//Getters
int Unit::get_cost() const {return cost;}
int Unit::get_damage() const{return damage;}
int Unit::get_cd() const {return cooldown;}
string Unit::get_name() const {return name;}
string Unit::get_EleType() const {return EleType;}

//Setters
void Unit::set_cost(int c) {cost = c;}
void Unit::set_damage(int d){ damage = d;}
void Unit::set_cd(int cool){cooldown = cd;}
void Unit::set_name(string n){name = n;}
void Unit::set_Type(string e){EleType = e;}
