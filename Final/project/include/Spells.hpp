#ifndef SPELL_HPP
#define SPELL_HPP

#include <string>
#include <vector>
using namespace std;

class Spell{
private:
  int cost;
  int damage;
  int hits;
  string name;
  string spellDesc;

public:

  //Default contructor
  Spell ();
  //Constructor
  Spell (int c, int d, int h, string n, string desc );

  // Copy Constructor
  //Spell(const Spell& other);

  //Move Constructor
  //Spell(Spell&& other);

  //Getters
  int get_cost();
  int get_damage();
  int get_hits();
  string get_name();
  string get_spellDesc();

  /*Function description : Checks if the spell has a heal component
  Input: Require player's atk dmg
  Output: return the amount of healing done by spell */
  int check_Effect(int PlayerATK);

  //Setters
  void set_cost(int c);
  void set_damage(int d);
  void set_hits(int h);
  void set_name(string n);
  void set_spellDesc(string desc);


};

vector<Spell> MakeSpellBook(int choice, std::string weapon, std::string element);

#endif // SPELL_HPP
