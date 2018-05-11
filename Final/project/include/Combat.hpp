#ifndef COMBAT_HPP
#define COMBAT_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ncurses.h>
#include <string>
#include "string_conversion.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
//#include "Display.hpp"
#include "Unit.hpp"
#include "Weapon.hpp"
#include "game-utility.hpp"

class Combat {
protected:
    int action;//takes in action from player
    int yshift = 1;//placement of cursor in y direction
    Player *p;
    Enemy *e;
	vector <std::string> combat_log;//takes in vector of strings to display combat log
	std::string temp_combat_log;
	WINDOW * combatwin;//Hold a pointer to the combat window screen
  //variables for max screen size
	int yMax;
	int xMax;

  public:
    //Default Constructor
    Combat();
    //Destructor
    ~Combat();
    //Overloaded Constructor
    Combat(Player *p_, Enemy *e_, int yMax_, int xMax_);
    /*
      Given: player action, character pick, pointer to player and enemy class
      returns: death state of both units
    */
    int combat_phase(unsigned int action_, int classPick, Player *p, Enemy *e);
    /*
      Given: element and weapon type for both player and enemy
      returns: float of the effective bonus damage to target
    */
    float eff_calc_other(std::string atkWeap, std::string atkEle, std::string defWeap, std::string defEle);
    /*
      calculates damage being done to enemy
    */
    void player_attack(Player *p, Enemy *e, unsigned int action, int classPick, float effect);
    /*
      calculates damage being done to player
    */
    void enemy_attack(Player *p, Enemy *e, float effect);

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
