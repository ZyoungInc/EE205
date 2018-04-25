#ifndef UNIT_HPP
#define UNIT_HPP

#include <utility>

class Unit {
protected:
  std::string name;
  int health;
  int MAXhealth;
  int mana;
  int attack;
  int defense;
public:

  Unit();
  // Constructs a unit with unit Variables
  Unit(std::string name_,
        int MAXhealth_,
        int mana_,
        int attack_,
        int defense_);

  // Copy Constructor
  Unit(const Unit& other);

  //Move Constructor
  Unit(Unit&& other);

  //Getters
  std::string get_name();
  int get_health();
  int get_mana();
  int get_attack();
  int get_defense();

  //Setters
  void set_name(std::string s);
  void set_health(int hp);
  void set_mana(int mp);
  void set_attack(int atk);
  void set_defense(int def);
};

#endif // UNIT_HPP
