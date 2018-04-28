#ifndef UNIT_HPP
#define UNIT_HPP

#include <utility>

class Unit {
protected:
  std::string name;
  int health;
  int MAXhealth;
  int mana;
  int MAXmana;
  int attack;
  int defense;
public:
<<<<<<< HEAD

  Unit();
  // Constructs a unit with unit Variables
=======
  //Default Constructor
  Unit();
  // Overloaded Constructs a unit with unit Variables
>>>>>>> a91e231d317c102b759e2e15b12df6ffdfc09042
  Unit(std::string name_,
        int MAXhealth_,
        int MAXmana_,
        int attack_,
        int defense_);

  // Copy Constructor
  Unit(const Unit& other);

  //Move Constructor
  Unit(Unit&& other);

  //Getters
  std::string get_name();
  int get_health();
  int get_MAXhealth();
  int get_mana();
  int get_MAXmana();
  int get_attack();
  int get_defense();

  //Setters
  void set_name(std::string s);
  void set_health(int hp);
  void set_MAXhealth(int hp);
  void set_mana(int mp);
  void set_MAXmana(int mp);
  void set_attack(int atk);
  void set_defense(int def);
};

#endif // UNIT_HPP
