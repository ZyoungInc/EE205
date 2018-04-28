#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>
#include "game-utility.hpp"
#include <utility>

//Base weapon class
class Weapon {
protected:
  std::string type;
  std::string rarity;
  int wdamage;
  int wdefense;

public:
  //Default Constructor
  Weapon();
  //Overloaded Constructor
  Weapon(std::string rarity_, std::string type_, int wdamage_, int wdefense_);
  //Getters
  std::string get_type();
  std::string get_rarity();
  int get_wdamage();
  int get_wdefense();
  //setters
  void set_type(std::string t);
  void set_rarity(std::string r);
  void set_wdamage(int dmg);
  void set_wdefense(int def);
};

class Warrior_Weap: public Weapon {
public:
  Warrior_Weap(unsigned char rarity_level);
};

class Mage_Weap: public Weapon {
public:
  Mage_Weap(unsigned char rarity_level);
};



#endif // WEAPON_HPP
