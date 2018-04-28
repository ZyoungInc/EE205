#ifndef COMBAT_HPP
#define COMBAT_HPP

#include <iostream>
#include <cstdlib>
#include "Enemy.hpp"
//#include "Player.hpp"
#include "display.hpp"
#include "unit.hpp"

class Combat {
protected:
    Unit& unit;
    Display& dialogue;
    int kills;
    std::string action;

  public:
    Player player;
    Enemy enemy;
    Combat(Unit& unit_, Display& display_, int kills_);
    void attack_other(Unit& other);
    void on_attack(int damage);
    bool is_dead();
    void on_death();
    void combat_phase();

    //Getters
    int get_kills();
    std::string get_action();
    //setters
    void set_kills(int k);
    void set_action(std::string a);

};

#endif // COMBAT_HPP
