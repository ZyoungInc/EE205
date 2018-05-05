#ifndef COMBAT_HPP
#define COMBAT_HPP

#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include "Enemy.hpp"
#include "Player.hpp"
//#include "Display.hpp"
#include "Unit.hpp"
#include "Weapon.hpp"
#include "game-utility.hpp"

class Combat {
protected:
    int souls;
    int action;
    int yshift = 1;
    Player *p;
    Enemy *e;

  public:
    //Default Constructor
    Combat();
    //Destructor
    ~Combat();
    //Overloaded Constructor
    Combat(Player *p_, Enemy *e_, int yMax_, int xMax_);
    int combat_phase(unsigned int action_, int classPick, Player *p, Enemy *e);
    float eff_calc_other(std::string atkWeap, std::string atkEle,
                        std::string defWeap, std::string defEle);
    void player_attack(Player *p, Enemy *e, unsigned int action, int classPick, float effect);
    void enemy_attack(Player *p, Enemy *e, float effect);
    bool is_dead();
    void on_death();

    //Getters
    int get_souls();
    int get_action();
    int get_yshift();
    //setters
    void set_souls(int s);
    void set_action(int a);
    void set_yshift(int y);

};

#endif // COMBAT_HPP
