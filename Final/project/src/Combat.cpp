#include <cstdlib>
#include <algorithm>
#include <string>
#include <ncurses.h>
#include "Combat.hpp"
#include "string_conversion.hpp"
#include "Unit.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Spells.hpp"
//#include "display.hpp"
#include "game-utility.hpp"
#include "Weapon.hpp"

//Defines the size of the combat log
#define MAX_COMBATLOG_SIZE 7

//Default Constructor
Combat::Combat() {}

//Destructor
Combat::~Combat() {}

//Overloaded Constructor
Combat::Combat(Player *p_, Enemy *e_, int yMax_, int xMax_)
{
	this->p = p_;
	this->e = e_;
	this->yMax = yMax_;
	this->xMax = xMax_;

	//create title window for game
	combatwin = newwin(yMax-12, xMax-1, 1, 1);
    box(combatwin, 0, 0);
    mvwprintw(combatwin, get_yshift(), 1, "You encounter a %s", e->get_name().c_str());
    set_yshift(1);
    refresh();
    wrefresh(combatwin);
}
/*
	calculates effective bonus damage for player
	player deals damage to enemy
	calculates effective bonus damage for enemy
	enemy deals damage to player if not dead
*/
int Combat::combat_phase(unsigned int action, int classPick, Player *p, Enemy *e)
  {
    float effect;
        effect = eff_calc_other(p->get_weapType(), p->get_eleType(),
							e->get_wep_type(), e->get_element());
        player_attack(p, e, action, classPick, effect);
    if(e->get_health() > 0)
    {
		effect = eff_calc_other(e->get_wep_type(), e->get_element(),
							p->get_weapType(), p->get_eleType());
		enemy_attack(p, e, effect);
    }

	//Iterate through combat log and display it on screen
	int cnt = 0;
	for(unsigned int i = combat_log.size(); i != 0; i--) {
		mvwprintw(combatwin, (2+cnt), 3, combat_log[(i-1)].c_str());
		cnt ++;
		wrefresh(combatwin);
	}

    if(e->get_health() == 0)
		return 1;
		//Enemy has died
    else if(p->get_health() == 0)
		return 2;
		//Player has died
    else
		return 3;
		//No one died, continue combat
  }

float Combat::eff_calc_other(std::string atkWeap, std::string atkEle,
                          std::string defWeap, std::string defEle) {
	float effect = 1;
	//Element triange
	if(atkEle == "Fire" && defEle == "Nature") effect = 1.2;
	else if(atkEle == "Fire" && defEle == "Water") effect = 0.8;
	else if(atkEle == "Water" && defEle == "Fire") effect = 1.2;
	else if(atkEle == "Water" && defEle == "Nature") effect = 0.8;
	else if(atkEle == "Nature" && defEle == "Water") effect = 1.2;
	else if(atkEle == "Nature" && defEle == "Fire") effect = 0.8;

	//Weapon Triangle
	else if(atkWeap == "Sword" && defWeap == "Axe") effect = 1.2;
	else if(atkWeap == "Sword" && defWeap == "Lance") effect = 0.8;
	else if(atkWeap == "Lance" && defWeap == "Sword") effect = 1.2;
	else if(atkWeap == "Lance" && defWeap == "Axe") effect = 0.8;
	else if(atkWeap == "Axe" && defWeap == "Lance") effect = 1.2;
	else if(atkWeap == "Axe" && defWeap == "Sword") effect = 0.8;
	else effect = 1;

	return effect;
}

void Combat::player_attack(Player *p, Enemy *e, unsigned int action, int classPick, float effect) {
	int damage;
	if(action == 2)
	{
		damage = std::max(0, int(p->get_attack() * effect - e->get_defense()));
		p->set_mana(20);
		//creates a string for combat damage
		temp_combat_log.clear();
		temp_combat_log.append("You dealt ");
		temp_combat_log.append(lexical_cast(damage));
		temp_combat_log.append(" damage to ");
		temp_combat_log.append(e->get_name());
		temp_combat_log.append(" with basic attack");

		if(combat_log.size() >= 5) {
			combat_log.erase(combat_log.begin());
			combat_log.push_back(temp_combat_log);
		}
		else {
			combat_log.push_back(temp_combat_log);
		}
	}
	else if(action == 7) {
		//Flee command
		if(combat_log.size() == MAX_COMBATLOG_SIZE) {
			combat_log.erase(combat_log.begin());
			combat_log.push_back("You've attempted to flee");
		}
		else {
			combat_log.push_back("You've attempted to flee");
		}
		damage = 0;
	}
	else {
		std::pair<int, int> spellDamage = p->cast_spell(classPick, action-3, p->get_attack());
		damage = std::max(0, spellDamage.second * int(spellDamage.first * effect - e->get_defense()));
		//creates a string for spell damage
		temp_combat_log.clear();
		temp_combat_log.append("You dealt ");
		temp_combat_log.append(lexical_cast(damage));
		temp_combat_log.append(" damage to ");
		temp_combat_log.append(e->get_name());
		temp_combat_log.append(" with ");
		temp_combat_log.append(p->get_spellName());

		if(combat_log.size() >= MAX_COMBATLOG_SIZE) {
			combat_log.erase(combat_log.begin());
			combat_log.push_back(temp_combat_log);
		}
		else {
			combat_log.push_back(temp_combat_log);
		}
	}
	e->set_health(-1 * damage);//deals damage to enemy
}

void Combat::enemy_attack(Player *p, Enemy *e, float effect){
	int damage = std::max(0, int(e->get_attack() * effect - p->get_defense()));

	temp_combat_log.clear();
	temp_combat_log.append(e->get_name());
	temp_combat_log.append(" dealt ");
	temp_combat_log.append(lexical_cast(damage));
	temp_combat_log.append(" damage to you ");

	if(combat_log.size() >= MAX_COMBATLOG_SIZE) {
		combat_log.erase(combat_log.begin());
		combat_log.push_back(temp_combat_log);
	}
	else {
		combat_log.push_back(temp_combat_log);
	}
	p->set_health(-1 * damage);//deals damage to player
}

//Getters
int Combat::get_action() {return action;}
int Combat::get_yshift() {return yshift;}

//setters
void Combat::set_action(int a) {action = a;}
void Combat::set_yshift(int y) {
	yshift += y;
	if(yshift == yMax-12)
	{
		wclear(combatwin);
		box(combatwin, 0, 0);
		yshift = 1;
	}
}
