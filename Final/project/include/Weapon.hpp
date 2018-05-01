#ifndef WEAPON_HPP
#define WEAPON_HPP
#include <string>
#include <utility>
#include "game-utility.hpp"

//Base weapon class
class Weapon {
protected:
  std::string type;
  std::string rarity;
  int wdamage;
  int wdefense;
  int MAXhealth;
  int MAXmana;

public:
  //Default Constructor
  Weapon();
  //Destructor
  ~Weapon();

  //Overloaded Constructor
  Weapon(std::string rarity_, std::string type_, int wdamage_, int wdefense_, int MAXhealth_, int MAXmana_);

  //Getters
  std::string get_type();
  std::string get_rarity();
  int get_wdamage();
  int get_wdefense();
  int get_MAXhealth();
  int get_MAXmana();

  //Setters
  void set_type(std::string t);
  void set_rarity(std::string r);
  void set_wdamage(int dmg);
  void set_wdefense(int def);
  void set_MAXhealth(int hp);
  void set_MAXmana(int mp);
};

//Warrior weapon for warrior class
class Warrior_Weap: public Weapon {
public:
  Warrior_Weap(unsigned char rarity_level);
};

//Mage weapon for mage class
class Mage_Weap: public Weapon {
public:
  Mage_Weap(unsigned char rarity_level);
};

#endif // WEAPON_HPP
