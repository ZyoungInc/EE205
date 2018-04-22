#ifndef COMBAT_HPP
#define COMBAT_HPP

#include <iostream>
#include <cstdlib>
//#include "Enemy.hpp"

class Combat {
  private:
    Unit& Unit;
    Display& Display;
    //Player& player
    //Enemy& enemy
  public:
    Combat(Unit& Unit_, Display& Display_);
    void attack_other(Unit& other);
    void on_attack(int damage);
    bool is_dead();
    void on_death();

};

#endif // COMBAT_HPP
